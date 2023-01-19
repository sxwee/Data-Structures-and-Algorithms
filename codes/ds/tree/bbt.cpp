#include "bbt.h"

int bbt::height(TreeNode *root)
{
    if (!root)
        return 0;
    return std::max(height(root->lchild), height(root->rchild)) + 1;
}

bool bbt::is_balanced(TreeNode *root)
{
    if (!root)
        return true;
    int hl = height(root->lchild);
    int hr = height(root->rchild);

    return (std::abs(hl - hr) <= 1) && is_balanced(root->lchild) && is_balanced(root->rchild);
}

// 插入结点
bbt::TreeNode *bbt::insert_node(TreeNode *root, int k)
{
    TreeNode *w = new TreeNode(k);
    TreeNode *z = root, *p = root, *f = nullptr, *fz = nullptr;
    while (p)
    {
        if (p->bf)
        {
            fz = p;
            z = p;
        }
        f = p;
        if (w->key < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!f)
        root = w;
    else if (w->key < f->key)
        f->lchild = w;
    else
        f->rchild = w;
    if (z)
    {
        if (w->key < z->key) // w插入到z的左子树上
        {
            p = z->lchild;
            z->bf++;
        }
        else
        {
            p = z->rchild;
            z->bf--;
        }
        // 修改自w到z的平衡因子
        while (p != w)
        {
            if (w->key < p->key)
            {
                p->bf = 1;
                p = p->lchild;
            }
            else
            {
                p->bf = -1;
                p = p->rchild;
            }
        }
        TreeNode *y, *x;
        // 对以z为根的子树进行旋转使得树重新平衡
        if (z->bf == 2) // 左旋
        {
            if (z->lchild->bf == 1) // LL类型
            {
                y = z->lchild;
                z->lchild = y->rchild;
                z->bf = 0;
                y->rchild = z;
                y->bf = 0;
                // 连接y与原z的双亲结点fz
                if (!fz)
                    root = y;
                else if (y->key < fz->key)
                    fz->lchild = y;
                else
                    fz->rchild = y;
            }
            else // LR类型
            {
                y = z->lchild, x = y->rchild;
                z->lchild = x->rchild;
                y->rchild = x->lchild;
                x->lchild = y;
                x->rchild = z;
                switch (x->bf)
                {
                case 0:
                    z->bf = y->bf = 0;
                    break;
                case 1:
                    z->bf = -1, y->bf = 0;
                    break;
                case -1:
                    z->bf = 0, y->bf = 1;
                    break;
                }
                // 连接x与原z的双亲结点
                if (!fz)
                    root = x;
                else if (x->key < fz->key)
                    fz->lchild = x;
                else
                    fz->rchild = x;
            }
        }
        else if (z->bf == -2) // 右旋
        {
            if (z->rchild->bf == -1) // RR类型
            {
                y = z->rchild;
                z->rchild = y->lchild;
                y->lchild = z;
                y->bf = 0;
                // 连接y与原z的双亲结点
                if (!fz)
                    root = y;
                else if (y->key < fz->key)
                    fz->lchild = y;
                else
                    fz->rchild = y;
            }
            else // RL类型
            {
                y = z->rchild, x = y->lchild;
                z->rchild = x->lchild;
                y->lchild = x->rchild;
                x->lchild = z;
                x->rchild = y;
                switch (x->bf)
                {
                case 0:
                    z->bf = y->bf = 0;
                    break;
                case 1:
                    z->bf = 0, y->bf = -1;
                    break;
                case -1:
                    z->bf = 1, y->bf = 0;
                    break;
                }
                //  连接x与原z的双亲结点
                if (!fz)
                    root = x;
                else if (x->key < fz->key)
                    fz->lchild = x;
                else
                    fz->rchild = x;
            }
        }
    }

    return root;
}

// 删除结点
bbt::TreeNode *bbt::delete_node(TreeNode *root, int k)
{
    return root;
}