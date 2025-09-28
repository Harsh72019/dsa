#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

struct Info {
    bool isBST;
    int size;
    int mindata;
    int maxdata;
    
    Info(bool isBST, int size, int mindata, int maxdata)
        : isBST(isBST), size(size), mindata(mindata), maxdata(maxdata) {}
};

class Solution {
public:
    int maxBSTSize = 0;

    Info helper(TreeNode* root) {
        if (!root)
            return Info(true, 0, INT_MAX, INT_MIN);

        Info left = helper(root->left);
        Info right = helper(root->right);

        if (left.isBST && right.isBST &&
            root->data > left.maxdata && root->data < right.mindata) {
            
            int currSize = left.size + right.size + 1;
            maxBSTSize = max(maxBSTSize, currSize);

            return Info(true, currSize, min(root->data, left.mindata), max(root->data, right.maxdata));
        }

        return Info(false, max(left.size, right.size), 0, 0);
    }

    int largestBST(TreeNode* root) {
        maxBSTSize = 0;
        helper(root);
        return maxBSTSize;
    }
};