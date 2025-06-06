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

 int solver(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        
        int left = max(0, solver(root->left, maxSum));  
        int right = max(0, solver(root->right, maxSum)); 
        
        maxSum = max(maxSum, root->val + left + right);
        
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solver(root, maxSum);
        return maxSum;
    }