#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

bool isParentSum(Node *root) {
    if (!root || (!root->left && !root->right))
        return true;

    int leftVal = root->left ? root->left->data : 0;
    int rightVal = root->right ? root->right->data : 0;

    return (root->data == leftVal + rightVal) &&
           isParentSum(root->left) &&
           isParentSum(root->right);
}
