#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"

using namespace std;

namespace bt
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
            if(root->lchild)
                q.push(root->lchild);
            if(root->rchild)
                q.push(root->rchild);
        }
    }
}

int main()
{
    vector<int> arr;
    return 0;
}