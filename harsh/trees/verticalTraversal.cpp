#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

   vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;
        
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int row, int col) {
            if (!node) return;
            nodes.push_back({col, row, node->val});
            dfs(node->left, row + 1, col - 1);
            dfs(node->right, row + 1, col + 1);
        };
        
        dfs(root, 0, 0);
    
        sort(nodes.begin(), nodes.end());
        
        vector<vector<int>> result;
        int last_col = INT_MIN;
        
        for (auto& [col, row, val] : nodes) {
            if (col != last_col) {
                result.push_back({});
                last_col = col;
            }
            result.back().push_back(val);
        }
        
        return result;
    }