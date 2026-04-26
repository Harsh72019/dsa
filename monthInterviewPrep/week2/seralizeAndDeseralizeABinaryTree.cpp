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
 

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        string result = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                result += "N,";
            }
        }

        return result;
    }

    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        stringstream ss(data);
        string item;

        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (!getline(ss, item, ','))
                break;
            if (item != "N")
            {
                node->left = new TreeNode(stoi(item));
                q.push(node->left);
            }

            if (!getline(ss, item, ','))
                break;
            if (item != "N")
            {
                node->right = new TreeNode(stoi(item));
                q.push(node->right);
            }
        }

        return root;
    }
};