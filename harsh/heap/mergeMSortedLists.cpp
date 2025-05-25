#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto head : lists)
    {
        ListNode *curr = head;
        while (curr != NULL)
        {
            pq.push(curr->val);
            curr = curr->next;
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    while (!pq.empty())
    {
        ListNode *temp = new ListNode(pq.top());
        pq.pop();
        curr->next = temp;
        curr = curr->next;
    }
    return dummy->next;
}