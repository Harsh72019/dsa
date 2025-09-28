#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<TreeNode *, TreeNode *> parentMap;
unordered_set<TreeNode *> visited;
vector<int> result;

void buildParent(TreeNode *node, TreeNode *parent)
{
    if (!node)
        return;
    parentMap[node] = parent;
    buildParent(node->left, node);
    buildParent(node->right, node);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    buildParent(root, nullptr);

    queue<pair<TreeNode *, int>> q;
    q.push({target, 0});
    visited.insert(target);

    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist == k)
        {
            result.push_back(curr->val);
        }

        if (dist > k)
            break;

        vector<TreeNode *> neighbors = {curr->left, curr->right, parentMap[curr]};
        for (TreeNode *neighbor : neighbors)
        {
            if (neighbor && !visited.count(neighbor))
            {
                visited.insert(neighbor);
                q.push({neighbor, dist + 1});
            }
        }
    }

    return result;
}