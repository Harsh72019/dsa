#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->data = val;
        left = right = NULL;
    }
};


void dfs(TreeNode* root , int col , int row , vector<tuple<int , int , int>>& tup) {
        if(root == nullptr) return;
        tup.push_back({col , row , root->data});
        dfs(root->left , col - 1 , row + 1 , tup);
        dfs(root->right , col + 1 , row + 1 , tup);
    }

    vector<int> bottomView(TreeNode *root) {
        vector<int> ans;
        vector<tuple<int , int , int>> nodes;
        dfs(root , 0 , 0 , nodes);

        sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b) {
            auto [col1, row1, val1] = a;
            auto [col2, row2, val2] = b;
            if (col1 != col2) return col1 < col2;
            return row1 < row2; 
        });

        map<int, int> colToVal;
        for (auto& [col, row, val] : nodes) {
            colToVal[col] = val;  
        }

        for (auto& [col, val] : colToVal) {
            ans.push_back(val);
        }

        return ans;
    }