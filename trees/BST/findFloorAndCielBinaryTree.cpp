#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

void solver(TreeNode *root, int key, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->data > key)
        ans[1] = min(ans[1], root->data);
    else
        ans[0] = max(ans[0], root->data);

    if (root->data > key)
        solver(root->left, key, ans);
    else
        solver(root->right, key, ans);
}
vector<int> floorCeilOfBST(TreeNode *root, int key)
{
    vector<int> ans{INT_MIN, INT_MAX};
    solver(root, key, ans);
    ans[0] = ans[0] == INT_MIN ? -1 : ans[0];
    ans[1] = ans[1] == INT_MAX ? -1 : ans[1];
    return ans;
}
