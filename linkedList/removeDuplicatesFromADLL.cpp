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

ListNode * removeDuplicates(ListNode *head) {
    if(!head->next)
        return head;
    ListNode * curr = head->next;
    int currCheck = head->val;
    ListNode* currentElement = head;
    while(curr)
    {
        if(curr->val == currCheck)
        {
            curr = curr->next;
        }
        else
        {
            currentElement->next = curr;
            curr->prev = currentElement;
            currentElement = curr;
            currCheck = curr->val;
        }
    }
    return head;
}