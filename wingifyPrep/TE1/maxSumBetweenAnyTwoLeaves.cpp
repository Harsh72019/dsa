#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int helper(TreeNode* root)
{
    if(!root)
        return 0;
    int left = helper(root->left);
    int right = helper(root->right);
    return root->val + max(left , right);
}

int maxSum(TreeNode* root)
{
    return helper(root);
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    cout<<maxSum(root);
    return 1;
}