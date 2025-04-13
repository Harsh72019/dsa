#include<bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0 , head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for(int i = 0 ; i <= n ; i++)
    {
        fast = fast->next;
    }
    while(fast)
    {
        slow  = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}