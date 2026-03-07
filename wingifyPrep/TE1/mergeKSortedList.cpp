#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data)
    {
        this->val = data;
    }
};

 ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int , vector<int> , greater<int>> minHeap;
        for(auto head : lists)
        {
            ListNode* curr = head;
            while(curr != NULL)
            {
                minHeap.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!minHeap.empty())
        {
            curr->next = new ListNode(minHeap.top());
            minHeap.pop();
            curr = curr->next;
        }
        return dummy->next;
    }