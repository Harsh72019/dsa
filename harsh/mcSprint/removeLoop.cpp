#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeLoop(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return head;

    slow = head;

    if (slow == fast)
    {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        return head;
    }

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;

    return head;
}
