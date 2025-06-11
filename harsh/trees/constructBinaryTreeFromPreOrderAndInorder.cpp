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

void helper(TreeNode* root, vector<int>& preorder, vector<int>& inorder) {
        int index = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        if (index == -1) return; 

        vector<int> inorderLeft(inorder.begin(), inorder.begin() + index);
        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + 1 + index);

        if (!preorderLeft.empty()) {
            TreeNode* leftNode = new TreeNode(preorderLeft[0]);
            root->left = leftNode;
            helper(leftNode, preorderLeft, inorderLeft);
        }

        vector<int> inorderRight(inorder.begin() + index + 1, inorder.end());
        vector<int> preorderRight(preorder.begin() + 1 + index, preorder.end());

        if (!preorderRight.empty()) {
            TreeNode* rightNode = new TreeNode(preorderRight[0]);
            root->right = rightNode;
            helper(rightNode, preorderRight, inorderRight);
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        helper(root, preorder, inorder);
        return root;
    }