#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *reverseALinkedList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}