#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int col, map<int, int>& topViewMap) {
        if (!root) return;

        if (topViewMap.find(col) == topViewMap.end())
            topViewMap[col] = root->data;

        dfs(root->left, col - 1, topViewMap);
        dfs(root->right, col + 1, topViewMap);
    }

    vector<int> topView(TreeNode* root) {
        map<int, int> topViewMap;
        dfs(root, 0, topViewMap);

        vector<int> result;
        for (auto& [col, val] : topViewMap)
            result.push_back(val);

        return result;
    }