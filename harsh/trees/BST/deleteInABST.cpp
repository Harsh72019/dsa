#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *findMin(TreeNode *node)
{
    while (node->left)
        node = node->left;
    return node;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if(!root)
        return NULL;
    if(root->val > key)
    {
        root->left = deleteNode(root->left , key);
    }
    else if(root->val < key)
    {
        root->right = deleteNode(root->right , key);
    }
    else{
        if(!root->left)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else{
            TreeNode * temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right , temp->val);
        }
    }
}