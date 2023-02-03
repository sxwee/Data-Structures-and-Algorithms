#include "rbt.h"

rbt::TreeNode::TreeNode(int key)
{
    this->key = key;
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->c = RED;
}

rbt::RBTree::RBTree()
{
    nil = new TreeNode(-1); // 设置哨兵结点
    root = nil;
    nil->c = BLACK;
}

void rbt::left_rotate(RBTree &t, TreeNode *x)
{
    TreeNode *y = x->right; // 获取x的右孩子
    x->right = y->left;     // x的右孩子指向y的左孩子
    if (y->left != t.nil)
        y->left->p = x;
    y->p = x->p; // x的父结点指向y
    if (x->p == t.nil)
        t.root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    y->left = x; // y的左孩子指针指向x
    x->p = y;
}

void rbt::right_rotate(RBTree &t, TreeNode *y)
{
    TreeNode *x = y->left; // 获取y的左孩子
    y->left = x->right;    // y的左孩子指向x的右子树
    if (x->right != t.nil)
        x->right->p = y;
    x->p = y->p; // x代替y的位置
    if (x->p == t.nil)
        t.root = x;
    else if (y->p->left == y)
        y->p->left = x;
    else
        y->p->right = x;
    x->right = y; // x的右孩子指向y
    y->p = x;
}

void rbt::rb_insert(RBTree &t, TreeNode *z)
{
    TreeNode *y = t.nil;  // 获取红黑树的哨兵结点
    TreeNode *x = t.root; // 获取红黑树的根节点
    // 寻找可插入的位置
    while (x != t.nil)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // 插入结点z
    z->p = y;
    if (y == t.nil)
        t.root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    z->left = t.nil;
    z->right = t.nil;
    z->c = RED;
    // 对树进行调整，使其重新恢复红黑树的性质
    rb_insert_fixup(t, z);
}

void rbt::rb_insert_fixup(RBTree &t, TreeNode *z)
{
    TreeNode *y;
    while (z->p->c == RED) // 父节点的颜色也是红色的
    {
        if (z->p == z->p->p->left) // 父节点是左结点
        {
            y = z->p->p->right; // z的叔结点
            if (y->c == RED)    // 情况一：z的叔结点y也是红色的
            {
                // 父节点和叔结点都变成黑色
                z->p->c = BLACK;
                y->c = BLACK;
                // 祖父结点变成红色
                z->p->p->c = RED;
                // z重新指向z的祖父结点重新进行循环
                z = z->p->p;
            }
            else
            {
                // 情况二：z的叔结点y是黑色的且z是一个右孩子, 通过左旋变成情况三
                if (z == z->p->right)
                {
                    z = z->p;
                    left_rotate(t, z);
                }
                // 情况三：z的叔结点y是黑色的且z是一个左孩子
                z->p->c = BLACK;
                z->p->p->c = RED;
                right_rotate(t, z->p->p);
            }
        }
        else // z的父节点是祖父结点的右孩子
        {
            y = z->p->p->left; // z的叔结点
            if (y->c == RED)   // 情况一：z的叔结点y也是红色的
            {
                // 父节点和叔结点都变成黑色
                z->p->c = BLACK;
                y->c = BLACK;
                // 祖父结点变成红色
                z->p->p->c = RED;
                // z重新指向z的祖父结点重新进行循环
                z = z->p->p;
            }
            else
            {
                // 情况二：z的叔结点y是黑色的且z是一个左孩子, 通过右旋变成情况三
                if (z == z->p->left)
                {
                    z = z->p;
                    right_rotate(t, z);
                }
                // 情况三：z的叔结点y是黑色的且z是一个右孩子
                z->p->c = BLACK;
                z->p->p->c = RED;
                left_rotate(t, z->p->p);
            }
        }
    }
    t.root->c = BLACK;
}

rbt::TreeNode *rbt::search(RBTree &t, int key)
{
    TreeNode *x = t.root;
    while (x != t.nil && x->key != key)
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

void rbt::rb_transplant(RBTree &t, TreeNode *u, TreeNode *v)
{
    if (u->p == t.nil)
        t.root = v;
    else if (u = u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    v->p = u->p;
}

void rbt::rb_delete(RBTree &t, int key)
{
    TreeNode *z = search(t, key);
    if (z == t.nil) // 没找到对应键，直接返回
        return;
    TreeNode *y = z;
    TreeNode *x;
    color org_y = y->c; // 保留y的原始颜色
    // 在红黑树t中删除特定键的结点
    if (y->left == t.nil) // 左孩子为空
    {
        x = z->right;
        rb_transplant(t, z, z->right);
    }
    else if (y->right == t.nil) // 右孩子为空
    {
        x = z->left;
        rb_transplant(t, z, z->left);
    }
    else // 左右孩子都存在
    {
        TreeNode *p = z->right; // 寻找z的后继结点y
        while (p != t.nil)
        {
            y = p;
            p = p->left;
        }
        org_y = y->c;
        x = y->right;
        if (y->p != z) // y不是z的右孩子
        {
            rb_transplant(t, y, y->right); // 用y的右孩子代替y的位置
            y->right = z->right;
            y->right->p = y;
        }
        rb_transplant(t, z, y); // 用y代替z
        y->left = z->left;
        y->left->p = y;
        y->c = z->c;
        if (org_y == BLACK) // y的原始颜色为黑色，删除或移动y会引起红黑性质的破坏
        {
            rb_delete_fixup(t, x); // x占据了原来y的位置
        }
    }
}

void rbt::rb_delete_fixup(RBTree &t, TreeNode *x)
{
    TreeNode *w;
    while (x != t.root && x->c == BLACK)
    {
        if (x == x->p->left) // x为其父节点的左节点
        {
            w = x->p->right; // w指向x的兄弟结点
            if (w->c == RED) // 情况一：x的兄弟结点是w是红色的
            {
                w->c = BLACK;
                x->p->c = RED;
                left_rotate(t, x->p);
                w = x->p->right;
            }
            if (w->left->c == BLACK && w->right->c == BLACK) // 情况二：x的兄弟w是黑色的，w的两个孩子都是黑色的。
            {
                w->c = RED;
                x = x->p;
            }
            else
            {
                // 情况三：x的兄弟结点w是黑色的，w的左孩子是红色的，右孩子是黑色的。
                if (w->right->c == BLACK)
                {
                    w->left->c = BLACK;
                    w->c = RED;
                    right_rotate(t, w);
                    w = x->p->right;
                }
                // 情况四：x的兄弟结点w是黑色的，且w的右孩子是红色的
                w->c = x->p->c;
                x->p->c = BLACK;
                w->right->c = BLACK;
                left_rotate(t, x->p);
                x = t.root;
            }
        }
        else // x为其父节点的右节点
        {
            w = x->p->left;  // w指向x的兄弟结点
            if (w->c == RED) // 情况一：x的兄弟结点是w是红色的
            {
                w->c = BLACK;
                x->p->c = RED;
                right_rotate(t, x->p);
                w = x->p->left;
            }
            if (w->right->c == BLACK && w->left->c == BLACK) // 情况二：x的兄弟w是黑色的，w的两个孩子都是黑色的。
            {
                w->c = RED;
                x = x->p;
            }
            else
            {
                // 情况三：x的兄弟结点w是黑色的，w的左孩子是红色的，右孩子是黑色的。
                if (w->left->c == BLACK)
                {
                    w->right->c = BLACK;
                    w->c = RED;
                    left_rotate(t, w);
                    w = x->p->left;
                }
                // 情况四：x的兄弟结点w是黑色的，且w的右孩子是红色的
                w->c = x->p->c;
                x->p->c = BLACK;
                w->left->c = BLACK;
                right_rotate(t, x->p);
                x = t.root;
            }
        }
    }
    x->c = BLACK;
}