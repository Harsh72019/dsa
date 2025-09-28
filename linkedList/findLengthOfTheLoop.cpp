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

int findLengthOfLoop(ListNode* head) {
    if (!head) return 0;
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (fast == NULL || fast->next == NULL) return 0;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* check = slow;
    int counter = 1;
    slow = slow->next;
    while (slow != check) {
        slow = slow->next;
        counter++;
    }
    return counter;
}