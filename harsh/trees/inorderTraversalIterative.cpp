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


vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Reach the leftmost node of the current node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Current must be null at this point
            curr = st.top();
            st.pop();
            ans.push_back(curr->val); // Add the node value

            // Visit the right subtree
            curr = curr->right;
        }

        return ans;
    }