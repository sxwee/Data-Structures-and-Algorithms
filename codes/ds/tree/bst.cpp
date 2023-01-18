#include "bst.h"

bst::TreeNode *bst::insert_node(TreeNode *root, int k)
{
    TreeNode *z = new TreeNode(k);
    if(!root)
        return z;
    TreeNode *pre, *p;
    pre = nullptr;
    p = root;
    while (p)
    {
        pre = p;
        if (z->key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    if (!pre) // root为一棵空树
        root = z;
    else if (z->key < pre->key)
        pre->left = z;
    else
        pre->right = z;
    return root;
}

bst::TreeNode *bst::build_binary_search_tree(vector<int> nums)
{
    TreeNode *root = nullptr;
    for (int num : nums)
    {
        root = bst::insert_node(root, num);
    }
    return root;
}

void bst::transplant(TreeNode *f, TreeNode *u, TreeNode *v)
{
    if (!f) // u为根结点
        u = v;
    else if (f->left == u)
        f->left = v;
    else
        f->right = v;
}

void bst::delete_node(TreeNode *root, int k)
{
    if (!root) // 空二叉搜索树直接返回
        return;
    // 寻找待删除的键值对应的结点及其父节点
    TreeNode *f, *p;
    f = nullptr;
    p = root;
    while (p && p->key != k)
    {
        f = p;
        if (k < p->key)
            p = p->left;
        else
            p = p->right;
    }
    if (!p) // 树中没有对应的结点
        return;
    // 开始删除结点
    if (!p->left) // p的左子树为空
        bst::transplant(f, p, p->right);
    else if (!p->right) // p的右子树为空
        bst::transplant(f, p, p->left);
    else
    {
        // 获取p的左子树和右子树根节点
        TreeNode *pl = p->left, *pr = p->right;
        TreeNode *ps = nullptr, *s = pr;
        while (s->left)
        {
            ps = s;
            s = s->left;
        }
        if (!ps) // s是p的右孩子
            pr = s->right;
        else // 将s的右子树替代s的位置
            ps->left = s->right;
        s->left = pl;
        s->right = pr;
        bst::transplant(f, p, s);
    }
}

bst::TreeNode *bst::search_node(TreeNode *root, int k)
{
    TreeNode *p = root;
    while (p && p->key != k)
    {
        if (k < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}