#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

    /*
    *非递归版本的前序遍历
    */
    void preorder_nre(TreeNode * root, vector<int> &ans)
    {
        stack<TreeNode *> s;
        while(root || !s.empty())
        {
            if(root)
            {
                ans.push_back(root->data);
                s.push(root);
                root = root->lchild;
            }
            else{
                root = s.top();
                s.pop();
                root = root->rchild;
            }
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
    
    /**
     * 非递归版本的中序遍历
    */
   void midorder_nre(TreeNode *root, vector<int> &ans)
   {
        stack<TreeNode *> s;
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root = root->lchild;
            }
            else{
                root = s.top();
                s.pop();
                ans.push_back(root->data);
                root = root->rchild;
            }
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

    // 非递归版本的后续遍历
    void lastorder_nre(TreeNode *root, vector<int> &ans)
    {
        stack<pair<TreeNode *, int>> s;
        while(root || !s.empty())
        {
            if(root)
            {
                cout << root->data << "-" << 0 << endl;
                s.push({root, 0});
                root = root->lchild;
            }
            else{
                auto temp = s.top();
                root = temp.first;
                s.pop();
                // 从左子树返回的
                if(temp.second == 0)
                {
                    s.push({root, 1});
                    root = root->rchild;
                    if(root)
                    {
                        cout << "r " << root->data << endl;
                        if(root->data == 7)
                            cout << "hello" << endl;
                    }
                }
                // 从右子树返回，此时需要访问根节点
                else{
                    ans.push_back(root->data);
                    root = NULL;
                }
            }
            if (root)
                cout << "b " << root->data << endl;
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
    vector<int> porder, porder1, morder, morder1, lorder, lorder1, lt;
    preorder(root, porder);  // 1 2 4 7 10 11 5 3 6 8 9
    preorder_nre(root, porder1); // 1 2 4 7 10 11 5 3 6 8 9
    midorder(root, morder);  // 4 10 7 11 2 5 1 8 6 9 3
    midorder_nre(root, morder1); // 4 10 7 11 2 5 1 8 6 9 3
    lastorder(root, lorder); // 10 11 7 4 5 2 8 9 6 3 1
    lastorder_nre(root, lorder1); // 10 11 7 4 5 2 8 9 6 3 1
    layer_travel(root, lt); // 1 2 3 4 5 6 7 8 9 10 11
    return 0;
}