#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    vector<int> inorder;
    int index;

    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    BSTIterator(TreeNode* root) {
        dfs(root);
        index = 0;
    }

    int next() {
        return inorder[index++];
    }

    bool hasNext() {
        return index < inorder.size();
    }
};



// Optimized version using stack

class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node)
    {
        while(node)
        {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right)
            pushLeft(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};