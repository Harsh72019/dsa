#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int ans = 0;

public:
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftHeight = 1 + height(root->left);
        int rightHeight = 1 + height(root->right);
        ans = max(ans, leftHeight + rightHeight - 2);
        return max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return ans;
    }
};