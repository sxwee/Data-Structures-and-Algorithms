
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
        this->lchild = NULL;
        this->rchild = NULL;
    }

    TreeNode()
    {
        this->lchild = NULL;
        this->rchild = NULL;
    }
};