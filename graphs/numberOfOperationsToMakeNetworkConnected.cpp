#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> parent , rank;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]); 
    } 

    bool unionByRank(int u , int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v) return false; 

        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        } else if (rank[ult_v] < rank[ult_u]) {
            parent[ult_v] = ult_u;
        } else {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
        return true; 
    }
};

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);
        int extraEdges = 0;

        for (auto& edge : connections) {
            if (!ds.unionByRank(edge[0], edge[1])) {
                extraEdges++; 
            }
        }

        unordered_set<int> uniqueParents;
        for (int i = 0; i < n; i++) {
            uniqueParents.insert(ds.findParent(i));
        }

        int components = uniqueParents.size();
        int requiredConnections = components - 1;

        return (extraEdges >= requiredConnections) ? requiredConnections : -1;
    }
