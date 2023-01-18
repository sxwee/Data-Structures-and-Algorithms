// balanced binary tree
#include <iostream>

namespace bbt
{
    class TreeNode
    {
    public:
        int data;                // 数据域
        struct TreeNode *lchild; // 左指针
        struct TreeNode *rchild; // 右指针
    public:
        TreeNode(int data)
        {
            this->data = data;
            this->lchild = nullptr;
            this->rchild = nullptr;
        }

        TreeNode()
        {
            this->lchild = nullptr;
            this->rchild = nullptr;
        }

        ~TreeNode()
        {
            delete this->lchild;
            delete this->rchild;
        }
    };

    // 获取二叉树的树高
    int height(TreeNode *root);

    // 判断二叉树是否为高度平衡
    bool is_balanced(TreeNode *root);
}