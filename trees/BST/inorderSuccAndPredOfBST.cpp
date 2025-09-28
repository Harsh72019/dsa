#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode *findPredecessor(TreeNode *root, int key)
{
    TreeNode *pred = nullptr;
    while (root)
    {
        if (root->data < key)
        {
            pred = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return pred;
}

TreeNode *findSuccessor(TreeNode *root, int key)
{
    TreeNode *succ = nullptr;
    while (root)
    {
        if (root->data > key)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return succ;
}

vector<int> succPredBST(TreeNode *root, int key)
{
    TreeNode *pred = findPredecessor(root, key);
    TreeNode *succ = findSuccessor(root, key);
    return {pred ? pred->data : -1, succ ? succ->data : -1};
}
