#include "link_list.h"

linked_list::Node::Node()
{
    this->val = 0;
    this->next = nullptr;
}

linked_list::Node::Node(int val)
{
    this->val = val;
    this->next = next;
}

linked_list::Node::~Node()
{
    delete this->next;
}

linked_list::Node *linked_list::list_insert(Node *head, Node *t)
{
    if (!head)
        return t;
    Node *p = head, *pre;
    while (p)
    {
        pre = p;
        p = p->next;
    }
    pre->next = t;
    return head;
}

linked_list::Node *linked_list::list_delete(Node *head, bool (*erase)(const int &x))
{
    if (!head)
        return nullptr;
    Node *pre, *p;
    Node *nh = new Node();
    nh->next = head;
    pre = nh;
    p = head;
    while (p)
    {
        if ((*erase)(p->val))
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return nh->next;
}

linked_list::Node *linked_list::list_reverse(Node *head)
{
    Node *p, *rear;
    Node *nh = new Node();
    rear = nh;
    p = head;
    while (p)
    {
        Node *t = p;
        p = p->next;
        t->next = rear->next;
        rear->next = t;
    }
    return nh->next;
}

linked_list::Node *linked_list::list_merge(Node *ha, Node *hb)
{
    Node *pa, *pb, *nh, *rear;
    nh = new Node();
    rear = nh;
    pa = ha, pb = hb;
    while (pa && pb)
    {
        if (pa->val < pb->val)
        {
            Node *t = pa;
            pa = pa->next;
            rear->next = t;
            rear = t;
        }
        else
        {
            Node *t = pb;
            pb = pb->next;
            rear->next = t;
            rear = t;
        }
    }

    if (pa)
        rear->next = pa;
    if (pb)
        rear->next = pb;
    return nh->next;
}