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

class Solution
{
public:
    void solver(ListNode *&curr, ListNode *last, int &ans)
    {
        if (last == nullptr)
            return;

        solver(curr, last->next, ans);

        ans = max(ans, curr->val + last->val);
        curr = curr->next;
    }
    int pairSum(ListNode *head)
    {
        int ans = 0;
        ListNode *curr = head;

        solver(curr, head, ans);

        return ans;
    }
};


class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        int ans = 0;

        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2)
        {
            ans = max(ans, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }

        return ans;
    }
};