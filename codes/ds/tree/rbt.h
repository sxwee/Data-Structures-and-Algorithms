// red-black tree
#include <iostream>

namespace rbt
{
    enum color
    {
        RED,
        BLACK
    };
    class TreeNode
    {
    public:
        int key;
        TreeNode *p, *left, *right; // 指向父结点、左孩子、右孩子的指针
        color c;                    // 颜色
    public:
        TreeNode(int key);
    };

    class RBTree
    {
    public:
        TreeNode *root;
        TreeNode *nil; // 哨兵结点
    public:
        RBTree();
    };

    TreeNode *search(RBTree &t, int key);                    // 搜索特定键对应的结点并返回
    void left_rotate(RBTree &t, TreeNode *x);                // 左旋
    void right_rotate(RBTree &t, TreeNode *y);               // 右旋
    void rb_transplant(RBTree &t, TreeNode *u, TreeNode *v); // 在红黑树T中用子树v代替子树u
    void rb_insert(RBTree &t, TreeNode *z);                  // 插入结点
    void rb_insert_fixup(RBTree &t, TreeNode *z);            // 插入后的调整
    void rb_delete(RBTree &t, int key);                      // 删除特定键对应的结点
    void rb_delete_fixup(RBTree &t, TreeNode *x);            // 删除后的调整
}