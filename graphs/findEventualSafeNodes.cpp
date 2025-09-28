#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> outDegree(n, 0);

        for (int u = 0; u < n; ++u) {
            outDegree[u] = graph[u].size();
            for (int v : graph[u]) {
                revAdj[v].push_back(u);  
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (outDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node); 

            for (int prev : revAdj[node]) {
                outDegree[prev]--;
                if (outDegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(ans.begin(), ans.end());  
        return ans;
    }