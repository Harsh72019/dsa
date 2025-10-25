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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = nullptr;
    ListNode *temp = nullptr;
    int carry = 0;
    ListNode *t1 = l1;
    ListNode *t2 = l2;

    while (t1 || t2 || carry)
    {
        int sum = 0;
        if (t1)
        {
            sum += t1->val;
            t1 = t1->next;
        }
        if (t2)
        {
            sum += t2->val;
            t2 = t2->next;
        }
        if (carry)
        {
            sum += carry;
        }
        carry = sum / 10;
        sum = sum % 10;

        ListNode *tempNode = new ListNode(sum);

        if (temp)
        {
            temp->next = tempNode;
        }
        else
        {
            result = tempNode;
        }

        temp = tempNode;
    }

    return result;
}