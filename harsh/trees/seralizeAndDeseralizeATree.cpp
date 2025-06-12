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


class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string s;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "#,";
            }
        }

        s.pop_back(); // remove trailing comma
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!getline(ss, str, ',')) break;
            if (str != "#") {
                TreeNode* left = new TreeNode(stoi(str));
                curr->left = left;
                q.push(left);
            }

            if (!getline(ss, str, ',')) break;
            if (str != "#") {
                TreeNode* right = new TreeNode(stoi(str));
                curr->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

