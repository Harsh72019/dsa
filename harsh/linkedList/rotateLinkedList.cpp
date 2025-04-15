#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k == 0) 
        return head;

   
    ListNode* curr = head;
    int listSize = 1;
    while(curr->next) {
        curr = curr->next;
        listSize++;
    }

    curr->next = head;

  
    k = k % listSize;
    ListNode* newTail = head;
    for(int i = 1 ; i < listSize - k ; i++)
    {
        newTail = newTail->next;
    }   
    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;


    return newHead;
}