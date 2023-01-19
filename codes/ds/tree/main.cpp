#include <iostream>
#include "bt.h"  // binary tree
#include "bst.h" // binary search tree
#include "bbt.h" // val tree

using namespace std;

int main()
{
    vector<int> arr = {
        1, 2, 3, 4, 5, 6, EMPTY, EMPTY, 7, EMPTY, EMPTY, 8, 9, 10, 11, EMPTY, EMPTY, EMPTY, EMPTY};

    /***************测试二叉树的构建与遍历算法***************/
    // using namespace btree;
    // TreeNode *root = build_binary_tree(arr);
    // vector<int> porder, porder1, morder, morder1, lorder, lorder1, lt;
    // preorder(root, porder);  // 1 2 4 7 10 11 5 3 6 8 9
    // preorder_nre(root, porder1); // 1 2 4 7 10 11 5 3 6 8 9
    // midorder(root, morder);  // 4 10 7 11 2 5 1 8 6 9 3
    // midorder_nre(root, morder1); // 4 10 7 11 2 5 1 8 6 9 3
    // lastorder(root, lorder); // 10 11 7 4 5 2 8 9 6 3 1
    // lastorder_nre(root, lorder1); // 10 11 7 4 5 2 8 9 6 3 1
    // layer_travel(root, lt); // 1 2 3 4 5 6 7 8 9 10 11

    /***************测试二叉树搜索树的构建与常见操作***************/
    // using namespace bst;
    // vector<int> nums = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    // TreeNode *root = build_binary_search_tree(nums);
    // TreeNode *p = search_node(root, 10);
    // root = insert_node(root, 15);
    // delete_node(root, 6);

    /***************测试AVL树的构建与常见操作***************/
    using namespace bbt;
    vector<int> nums = {1, 4, 2, 8, 10, 14, 6, 3};
    TreeNode *root = nullptr;
    for (int num : nums)
    {
        root = insert_node(root, num);
    }
    return 0;
}