#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int solver(TreeNode* root)
    {
        if(!root)
            return 0;
        int leftH = 1 + solver(root->left);
        int rightH = 1 + solver(root->right);
        return max(leftH , rightH);
    }
    int maxDepth(TreeNode* root) {
        return solver(root);
    }
};