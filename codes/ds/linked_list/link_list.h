#include <iostream>
#include <vector>

namespace linked_list
{
    class Node
    {
    public:
        int val;
        Node *next;

    public:
        Node();
        Node(int val);
        ~Node();
    };

    Node *list_insert(Node *head, Node *t);              // 往链表尾插入结点
    Node *list_delete(Node *head, bool (*erase)(const int &x)); // 删除满足特定条件的结点
    Node *list_reverse(Node *head);                      // 反转链表
    Node *list_merge(Node *ha, Node *hb);                // 归并两个有序链表
}