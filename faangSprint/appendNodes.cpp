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

Node *addNodes(Node *head, int n, int m)
{
    if (!head)
        return nullptr;

    Node *curr = head;

    while (curr)
    {
        for (int i = 1; i < m && curr->next; i++)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;
        int sum = 0, count = 0;

        for (int i = 0; i < n && temp; i++)
        {
            sum += temp->data;
            temp = temp->next;
            count++;
        }

        if (count > 0)
        {
            Node *sumNode = new Node(sum);
            Node *tail = curr;

            for (int i = 0; i < count && tail->next; i++)
            {
                tail = tail->next;
            }

            sumNode->next = tail->next;
            tail->next = sumNode;

            curr = sumNode->next;
        }
        else
        {
            break;
        }
    }

    return head;
}
