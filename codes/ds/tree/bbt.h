// balanced binary tree (AVL)
#include <iostream>

namespace bbt
{
    class TreeNode
    {
    public:
        int key;                 // 数据域
        struct TreeNode *lchild; // 左指针
        struct TreeNode *rchild; // 右指针
        int bf;                  // 以该结点为根的子树的平衡因子
    public:
        TreeNode(int key)
        {
            this->key = key;
            this->bf = 0;
            this->lchild = nullptr;
            this->rchild = nullptr;
        }

        TreeNode()
        {
            this->bf = 0;
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

    // 插入结点
    TreeNode *insert_node(TreeNode *root, int k);

    // 删除结点
    TreeNode *delete_node(TreeNode *root, int k);
}