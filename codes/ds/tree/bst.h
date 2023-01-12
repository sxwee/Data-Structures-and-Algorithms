// binary search tree
#include <iostream>
#include <vector>

using std::vector;

namespace bst
{
    class TreeNode
    {
    public:
        int key;
        // int data; // 为简便，忽略数据域
        TreeNode *left, *right;

    public:
        TreeNode()
        {
            this->left = nullptr;
            this->right = nullptr;
        }
        TreeNode(int key)
        {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
        }
        ~TreeNode()
        {
            delete this->left;
            delete this->right;
        }
    };

    // 在二叉搜索树中插入键值为k的结点
    void insert_node(TreeNode *root, int k);


    // 从空树开始构建二叉搜索树
    TreeNode *build_binary_search_tree(vector<int> nums);

    // 在二叉搜索树中删除键值为k的结点
    void delete_node(TreeNode *root, int k);

    // 在二叉树中搜索特定键值的结点并返回
    TreeNode *search_node(TreeNode *root, int k);
}