#include "bbt.h"

int bbt::height(TreeNode *root)
{
    if(!root)
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