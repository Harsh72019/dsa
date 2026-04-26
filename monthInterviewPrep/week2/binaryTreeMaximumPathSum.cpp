#include<bits/stdc++.h>
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


class Solution {
public:
    int maxSum = INT_MIN;

    int solver(TreeNode* root)
    {
        if(!root)
            return 0;

        int lMax = max(0, solver(root->left));
        int rMax = max(0, solver(root->right));

        maxSum = max(maxSum, root->val + lMax + rMax);

        return root->val + max(lMax, rMax);
    }

    int maxPathSum(TreeNode* root) {
        solver(root);
        return maxSum;
    }
};