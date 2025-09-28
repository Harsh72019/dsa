#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void solver(TreeNode* root, vector<vector<int>>& ans, vector<int>& curr) {
        if (root == NULL)
            return;

        curr.push_back(root->data); 

        if (!root->left && !root->right) {
            ans.push_back(curr);     
        } else {
            solver(root->left, ans, curr);
            solver(root->right, ans, curr);
        }

        curr.pop_back();  
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> curr;
        solver(root, ans, curr);
        return ans;
    }