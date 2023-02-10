#include <iostream>
#include <vector>
#include "link_list.h"

using namespace std;
using namespace linked_list;

void travel(Node *head)
{
    Node *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

bool is_even(const int &x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> nums = {1, 4, 7, 10};
    vector<int> nums1 = {3, 6, 10, 12, 20};
    Node *ha, *hb;
    ha = hb = nullptr;
    // 创建链表
    for (int num : nums)
    {
        ha = list_insert(ha, new Node(num));
    }
    for (int num : nums1)
    {
        hb = list_insert(hb, new Node(num));
    }
    travel(ha); // 1 4 7 10
    travel(hb); // 3 6 10 12 20
    // 删除链表中满足特定条件的结点
    list_delete(ha, is_even);
    travel(ha); // 1 7
    // 归并两个有序链表
    Node *hc = list_merge(ha, hb);
    travel(hc); // 1 3 6 7 10 12 20
    // 对链表翻转
    Node *hd = list_reverse(hc);
    travel(hd); // 20 12 10 7 6 3 1
    return 0;
}