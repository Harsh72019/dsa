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

    void solveLeft(TreeNode* root , vector<int>& ans , bool left)
    {
        if(!root)
            return;
        if(left)
            ans.push_back(root->data);
        else
            if(!root->left && !root->right) ans.push_back(root->data);
        solveLeft(root->left , ans , left);
        solveLeft(root->right , ans , false);
    }
    void solveRight(TreeNode* root , vector<int>& ans , bool right)
    {
        if(!root)
            return;
        if(right)
            ans.push_back(root->data);
        else
            if(!root->left && !root->right) ans.push_back(root->data);
        solveRight(root->right , ans , right);
        solveRight(root->left , ans , false);
    }
    vector <int> boundary(TreeNode* root){
        if(!root)
        {
            return {};
        }
    	vector<int> leftHalf;
        leftHalf.push_back(root->data );
        solveLeft(root->left , leftHalf , true);
        vector<int> rightHalf;
        solveRight(root->right , rightHalf , true);
        reverse(rightHalf.begin() , rightHalf.end());
        leftHalf.insert(leftHalf.end()  , rightHalf.begin() , rightHalf.end());
        return leftHalf;      
    }


    int main(){

    //    create a tree like this  [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]

        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->right = new TreeNode(6);

        vector<int> ans = boundary(root);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }

        return 0;
    }