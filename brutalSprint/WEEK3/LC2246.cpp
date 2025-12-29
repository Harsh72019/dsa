#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 1;

    int dfs(int node, int parent, vector<vector<int>> &adj, string &s)
    {
        int longest = 0;
        int secondLongest = 0;

        for (int child : adj[node])
        {
            if (child == parent)
                continue;

            int childLen = dfs(child, node, adj, s);

            if (s[child] == s[node])
                continue;

            if (childLen > longest)
            {
                secondLongest = longest;
                longest = childLen;
            }
            else if (childLen > secondLongest)
            {
                secondLongest = childLen;
            }
        }

        ans = max(ans, longest + secondLongest + 1);

        return longest + 1;
    }

    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        dfs(0, -1, adj, s);
        return ans;
    }
};
