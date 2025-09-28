#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        TreeNode *newNode = new TreeNode(val);
        return newNode;
    }
    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}