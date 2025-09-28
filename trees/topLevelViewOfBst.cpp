#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int col, map<int, int>& topViewMap) {
        if (!root) return;

        if (topViewMap.find(col) == topViewMap.end())
            topViewMap[col] = root->data;

        dfs(root->left, col - 1, topViewMap);
        dfs(root->right, col + 1, topViewMap);
    }

    vector<int> topView(TreeNode* root) {
        map<int, int> topViewMap;
        dfs(root, 0, topViewMap);

        vector<int> result;
        for (auto it = topViewMap.begin(); it != topViewMap.end(); ++it) {
            result.push_back(it->second);
}
        return result;
    }

    
    int main(){
        // Create a tree like this
    //       1
    //  /   \
    // 2     3
    //  \   / \
    //   4 5   6

        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(5);
        root->right->right = new TreeNode(6);

       

        vector<int> ans = topView(root);
        for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
        }
        return 0;
    }