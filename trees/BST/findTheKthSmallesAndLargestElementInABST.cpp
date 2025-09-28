#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        val = val;
        left = NULL;
        right = NULL;
    }
};

void solver(TreeNode *root, vector<int> &inorder)
{
    if (!root)
        return;
    solver(root->left, inorder);
    inorder.push_back(root->val);
    solver(root->right, inorder);
}
pair<int, int> kthSmallestAndLargest(TreeNode *root, int k)
{
    vector<int> inorder;
    solver(root, inorder);
    return {inorder[k - 1], inorder[inorder.size() - k]};
}