#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};


vector<int> numOfIslandsII(int n , int m , vector<vector<int>>& operations)
{
    DisjointSet s (n * m);
    vector<vector<bool>> visited (n , vector<bool> (m , false));
    vector<int> ans;

    vector<int> dx = {0 , 0 , 1 , -1};
    vector<int> dy = {1 , -1 , 0 , 0};

    int count = 0;

    for(auto &op :  operations)
    {
        int row = op[0];
        int col = op[1];
        int node = row * m + col;

        if(visited[row][col])
        {
            ans.push_back(count);
            continue;
        }

        count++;

        visited[row][col] = true;

        for(int d = 0 ; d < 4 ; d++)
        {
            int newRow = row + dx[d];
            int newCol = col + dy[d];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol])
            {
                int newNode = newRow * m + newCol;
                if (s.findParent(node) != s.findParent(newNode)) {
                        s.unionByRank(node, newNode);
                        count--; 
                }
            }
        }

        ans.push_back(count);
    }

    return ans;

}