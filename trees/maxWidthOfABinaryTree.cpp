#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int size = q.size();
        unsigned long long minIndex = q.front().second;
        unsigned long long first, last;
        for (int i = 0; i < size; i++) {
            auto it = q.front();
            q.pop();
            it.second -= minIndex; 
            if (i == 0) first = it.second;
            if (i == size - 1) last = it.second;
            if (it.first->left) q.push({it.first->left, 2 * it.second + 1});
            if (it.first->right) q.push({it.first->right, 2 * it.second + 2});
        }
        maxWidth = max(maxWidth, int(last - first + 1));
    }

    return maxWidth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << widthOfBinaryTree(root) << endl; 
    return 0;
}
