#include "binary_tree.h"

void btree::preorder(TreeNode *root, vector<int> &ans)
{
    if (root)
    {
        ans.push_back(root->data);
        preorder(root->lchild, ans);
        preorder(root->rchild, ans);
    }
}

void btree::preorder_nre(TreeNode *root, vector<int> &ans)
{
    using std::stack;
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        if (root)
        {
            ans.push_back(root->data);
            s.push(root);
            root = root->lchild;
        }
        else
        {
            root = s.top();
            s.pop();
            root = root->rchild;
        }
    }
}

void btree::midorder(TreeNode *root, vector<int> &ans)
{
    if (root)
    {
        midorder(root->lchild, ans);
        ans.push_back(root->data);
        midorder(root->rchild, ans);
    }
}

void btree::midorder_nre(TreeNode *root, vector<int> &ans)
{
    using std::stack;
    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        if (root)
        {
            s.push(root);
            root = root->lchild;
        }
        else
        {
            root = s.top();
            s.pop();
            ans.push_back(root->data);
            root = root->rchild;
        }
    }
}

void btree::lastorder(TreeNode *root, vector<int> &ans)
{
    if (root)
    {
        lastorder(root->lchild, ans);
        lastorder(root->rchild, ans);
        ans.push_back(root->data);
    }
}

void btree::lastorder_nre(TreeNode *root, vector<int> &ans)
{
    using std::pair;
    using std::stack;
    stack<pair<TreeNode *, int>> s;
    while (root || !s.empty())
    {
        if (root)
        {
            s.push({root, 0});
            root = root->lchild;
        }
        else
        {
            auto temp = s.top();
            root = temp.first;
            s.pop();
            // 从左子树返回的
            if (temp.second == 0)
            {
                s.push({root, 1});
                root = root->rchild;
            }
            // 从右子树返回，此时需要访问根节点
            else
            {
                ans.push_back(root->data);
                root = NULL;
            }
        }
    }
}

void btree::layer_travel(TreeNode *root, vector<int> &ans)
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

btree::TreeNode *btree::build_binary_tree(vector<int> &nums)
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

int btree::height(TreeNode *root)
{
    if(!root)
        return 0;
    return std::max(height(root->lchild), height(root->rchild)) + 1;
}

bool btree::is_balanced(TreeNode *root)
{
    if(!root)
        return true;
    int hl = height(root->lchild);
    int hr = height(root->rchild);

    return (std::abs(hl - hr) <= 1) && is_balanced(root->lchild) && is_balanced(root->rchild);
}