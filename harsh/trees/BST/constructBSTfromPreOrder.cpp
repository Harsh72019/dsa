#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solver(TreeNode* root , int value )
    {
        if(!root)
            return new TreeNode(value);
        if(root->val > value)
            root->left = solver(root->left , value);
        else
            root->right = solver(root->right , value);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(!preorder.size())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size() ; i++)
        {
            root = solver(root , preorder[i]);
        }
        return root;
    }


    // Optimized

    TreeNode* buildBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index >= preorder.size()) return nullptr;
    int val = preorder[index];
    if (val < minVal || val > maxVal) return nullptr;

    TreeNode* root = new TreeNode(val);
    index++;
    root->left = buildBST(preorder, index, minVal, val);
    root->right = buildBST(preorder, index, val, maxVal);
    return root;
}

