
// binary tree
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define EMPTY -1

using std::vector, std::stack, std::queue;

namespace btree
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

    // 递归版本的前序遍历
    void preorder(TreeNode *root, vector<int> &ans);

    // 非递归版本的前序遍历
    void preorder_nre(TreeNode *root, vector<int> &ans);

    // 递归版本的中序遍历
    void midorder(TreeNode *root, vector<int> &ans);

    // 非递归版本的中序遍历
    void midorder_nre(TreeNode *root, vector<int> &ans);

    // 递归版本的后序遍历
    void lastorder(TreeNode *root, vector<int> &ans);

    // 非递归版本的后序遍历
    void lastorder_nre(TreeNode *root, vector<int> &ans);

    // 层次遍历
    void layer_travel(TreeNode *root, vector<int> &ans);

    // 层次遍历的方式构建二叉树, 用-1表示空
    TreeNode *build_binary_tree(vector<int> &nums);

    // 求二叉树的树高
    int height(TreeNode * root);
}