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

 vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);  

        vector<vector<int>> ans;
        vector<int> level;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                ans.push_back(level);
                level.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                level.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return ans;
    }