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
    if(!root) return {};
    
    queue<TreeNode*> nodes;
    vector<vector<int>> ans;
    vector<int> level;
    nodes.push(root);
    nodes.push(NULL);
    while(!nodes.empty())
    {
        TreeNode* node = nodes.front();
        nodes.pop();

        if(node == NULL)
        {
            ans.push_back(level);
            level.clear();
            if(!nodes.empty())
            {
                nodes.push(NULL);
            }
        }
        else{
            level.push_back(node->val);
            if(node->left) nodes.push(node->left);
            if(node->right) nodes.push(node->right);
        }
    }
    return ans;
}


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);
    cout<<"here"<<endl;
    for(int i = 0 ; i < ans.size() ; i++)
    {
        for(int j = 0 ; j < ans[i].size() ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}