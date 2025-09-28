#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) 
    {
        return nullptr;
    }

    ListNode* prev = NULL;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next =slow->next;
    delete slow;
    return head;
}