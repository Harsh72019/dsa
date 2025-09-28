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


bool solve(ListNode*& head, ListNode* tail) {
    if (!tail) return true;

    bool check = solve(head, tail->next);
    if (!check) return false;

    if (head->val != tail->val) return false;

    head = head->next;
    return true;
}

bool isPalindrome(ListNode* head) {
    return solve(head, head);
}