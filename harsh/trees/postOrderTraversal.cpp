#include<bits/stdc++.h>
using namespace std;    

struct Node{
    int data;
    Node* left;
    Node* right;
};

void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
