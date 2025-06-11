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
    unordered_map<int, vector<int>> graph;

    void dfs(TreeNode* curr, TreeNode* parent) {
        if (!curr) return;
        if (parent) {
            graph[curr->data].push_back(parent->data);
            graph[parent->data].push_back(curr->data);
        }
        dfs(curr->left, curr);
        dfs(curr->right, curr);
    }

    int timeToBurnTree(TreeNode* root, int start) {
        dfs(root, nullptr);

        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                for (int neighbor : graph[curr]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                        burned = true;
                    }
                }
            }
            if (burned) time++;
        }

        return time;
    }