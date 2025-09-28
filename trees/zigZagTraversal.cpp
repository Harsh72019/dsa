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
 
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool isRight = true;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                if (!isRight)
                    reverse(level.begin(), level.end()); 

                ans.push_back(level);
                level.clear();

                if (!q.empty())
                    q.push(NULL);

                isRight = !isRight; 
            } else {
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ans;
    }