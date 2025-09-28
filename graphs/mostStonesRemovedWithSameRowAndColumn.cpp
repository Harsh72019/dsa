#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findPar(u);
        int ult_v = findPar(v);
        if (ult_u == ult_v) return;

        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;

        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet dsu(maxRow + maxCol + 2);
        unordered_set<int> uniqueNodes;

        for (auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;

            dsu.unionBySize(rowNode, colNode);

            uniqueNodes.insert(rowNode);
            uniqueNodes.insert(colNode);
        }

        int components = 0;
        for (int node : uniqueNodes) {
            if (dsu.findPar(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
