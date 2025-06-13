#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void morrisInorderTraversal(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if(prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    for(int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
}

void morrisPreorderTraversal(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if(prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    for(int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
}