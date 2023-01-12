#include "bst.h"

void bst::insert_node(TreeNode *root, int k)
{
    // 创建键值为k的新结点
    TreeNode *node = new TreeNode(k);
    TreeNode *pre, *p;
    pre = nullptr;
    p = root;
    while (p)
    {
        pre = p;
        if (node->key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    if (!pre) // root为一棵空树
        p = node;
    else if (node->key < pre->key)
        pre->left = node;
    else
        pre->right = node;
}

bst::TreeNode *bst::build_binary_search_tree(vector<int> nums)
{
    TreeNode *root = nullptr;
    for (int num : nums)
    {
        bst::insert_node(root, num);
    }
    return root;
}

void bst::delete_node(TreeNode *root, int k)
{
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