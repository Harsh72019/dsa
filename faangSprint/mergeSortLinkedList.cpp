#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (a && b)
    {
        if (a->val <= b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

ListNode *splitMiddle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *slow = head;
    ListNode *fast = head->next; 
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr; 
    return mid;
}

ListNode *mergeSortList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *mid = splitMiddle(head);
    ListNode *left = mergeSortList(head);
    ListNode *right = mergeSortList(mid);
    return mergeTwoLists(left, right);
}
