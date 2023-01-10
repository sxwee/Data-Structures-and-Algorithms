#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "binary_tree.h"

using namespace std;
using namespace btree;

int main()
{
    vector<int> arr = {
        1, 2, 3, 4, 5, 6, EMPTY, EMPTY, 7, EMPTY, EMPTY, 8, 9, 10, 11, EMPTY, EMPTY, EMPTY, EMPTY};
    
    // 测试二叉树的构建与遍历算法
    TreeNode *root = build_binary_tree(arr);
    vector<int> porder, porder1, morder, morder1, lorder, lorder1, lt;
    preorder(root, porder);  // 1 2 4 7 10 11 5 3 6 8 9
    preorder_nre(root, porder1); // 1 2 4 7 10 11 5 3 6 8 9
    midorder(root, morder);  // 4 10 7 11 2 5 1 8 6 9 3
    midorder_nre(root, morder1); // 4 10 7 11 2 5 1 8 6 9 3
    lastorder(root, lorder); // 10 11 7 4 5 2 8 9 6 3 1
    lastorder_nre(root, lorder1); // 10 11 7 4 5 2 8 9 6 3 1
    layer_travel(root, lt); // 1 2 3 4 5 6 7 8 9 10 11
    // 获取二叉树的树高
    cout << "tree height: " << height(root) << endl;
    // 判断二叉树是否平衡
    cout << "is balanced: " << is_balanced(root) << endl;
    return 0;
}