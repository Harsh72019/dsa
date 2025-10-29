#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (!head)
        return head;
    ListNode *curr = head;
    ListNode *next = head->next;
    while (next)
    {
        swap(curr->val, next->val);
        if (next->next)
        {
            curr = next->next;
            next = curr->next;
        }
        else
            break;
    }
    return head;
}