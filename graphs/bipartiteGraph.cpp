#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>> &graph, int node, int color, vector<int>& colors) {
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                if (!dfs(graph, neighbor, 1 - color, colors)) return false;
            } else if (colors[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1); 

        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {
                if (!dfs(graph, i, 0, colors))
                    return false;
            }
        }

        return true;
    }