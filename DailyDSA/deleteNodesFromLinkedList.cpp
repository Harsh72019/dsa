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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        // dummy->next = head;
        set<int> st(nums.begin(), nums.end());
        ListNode *mainCurr = dummy;
        ListNode *curr = head;
        while (curr != NULL)
        {
            if (st.find(curr->val) != st.end())
            {
                curr = curr->next;
            }
            else
            {
                mainCurr->next = curr;
                mainCurr = mainCurr->next;
                curr = curr->next;
            }
        }
        mainCurr->next = NULL;
        return dummy->next;
    }
};