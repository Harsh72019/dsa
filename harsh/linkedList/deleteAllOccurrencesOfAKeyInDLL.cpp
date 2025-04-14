#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode* deleteAllOccurrences(ListNode* head, int target) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    if(head) head->prev = dummy;

    ListNode* curr = dummy;
    while(curr->next) {
        if(curr->next->val == target) {
            ListNode* toDelete = curr->next;
            curr->next = toDelete->next;
            if(toDelete->next) {
                toDelete->next->prev = curr;
            }
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }

    head = dummy->next;
    if(head) head->prev = nullptr; 
    delete dummy;
    return head;
}