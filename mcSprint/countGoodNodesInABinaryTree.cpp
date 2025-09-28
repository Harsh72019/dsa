#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solver(TreeNode *curr, int maxSoFar)
{
    if (!curr)
        return 0;

    int count = 0;
    if (curr->val >= maxSoFar)
    {
        count = 1;
        maxSoFar = curr->val;
    }

    count += solver(curr->left, maxSoFar);
    count += solver(curr->right, maxSoFar);
    return count;
}

int goodNodes(TreeNode *root)
{
    return solver(root, root->val);
}