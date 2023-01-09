#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"
#define EMPTY -1

using namespace std;

namespace binary_tree
{
    // 递归版本的先序遍历
    void preorder(TreeNode *root, vector<int> &ans)
    {
        if (root)
        {
            ans.push_back(root->data);
            preorder(root->lchild, ans);
            preorder(root->rchild, ans);
        }
    }

    // 递归版本的中序遍历
    void midorder(TreeNode *root, vector<int> &ans)
    {
        if (root)
        {
            midorder(root->lchild, ans);
            ans.push_back(root->data);
            midorder(root->rchild, ans);
        }
    }

    // 递归版本的后序遍历
    void lastorder(TreeNode *root, vector<int> &ans)
    {
        if (root)
        {
            lastorder(root->lchild, ans);
            lastorder(root->rchild, ans);
            ans.push_back(root->data);
        }
    }

    // 层次遍历
    void layer_travel(TreeNode *root, vector<int> &ans)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur_node = q.front();
            q.pop();
            ans.push_back(cur_node->data);
            if (cur_node->lchild)
                q.push(cur_node->lchild);
            if (cur_node->rchild)
                q.push(cur_node->rchild);
        }
    }

    /**
     * 层次遍历的方式构建二叉树
     * 用-1表示空
     */
    TreeNode *build_binary_tree(vector<int> &nums)
    {
        int n = nums.size();
        TreeNode *root = new TreeNode();
        int i = 0;
        root->data = nums[i++];
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur_node = q.front();
            q.pop();
            // create left child node
            if (i < n)
            {
                if (nums[i] != EMPTY)
                {
                    TreeNode *lnode = new TreeNode();
                    lnode->data = nums[i];
                    cur_node->lchild = lnode;
                    q.push(lnode);
                }
                i++;
            }
            // create right child node
            if (i < n)
            {
                if (nums[i] != EMPTY)
                {
                    TreeNode *rnode = new TreeNode();
                    rnode->data = nums[i];
                    cur_node->rchild = rnode;
                    q.push(rnode);
                }
                i++;
            }
        }
        return root;
    }
}

int main()
{
    vector<int> arr = {
        1, 2, 3, 4, 5, 6, EMPTY, EMPTY, 7, EMPTY, EMPTY, 8, 9, 10, 11, EMPTY, EMPTY, EMPTY, EMPTY};
    using namespace binary_tree;
    TreeNode *root = build_binary_tree(arr);
    vector<int> porder, morder, lorder, lt;
    preorder(root, porder);  // 1 2 4 7 10 11 5 3 6 8 9
    midorder(root, morder);  // 4 10 7 11 2 5 1 8 6 9 3
    lastorder(root, lorder); // 10 11 7 4 5 2 8 9 6 3 1
    layer_travel(root, lt);  // 1 2 3 4 5 6 7 8 9 10 11
    return 0;
}