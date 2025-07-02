#include<bits/stdc++.h>
using namespace std;

class DisjointSet { 
    vector<int> rank , parent;
public:
    DisjointSet(int n )
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n )
    {
        if(n == parent[n])
            return n;
        return parent[n] = findParent(parent[n]); // path compression
    }

    void unionByRank(int u , int v) 
    {
        int ult_u  = findParent(u);
        int ult_v = findParent(v);

        if(ult_u == ult_v)
            return;

        if(rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }

    }
};


int spanningTree(int N , vector<vector<int>> & edges)
{
    vector<pair<int , pair<int , int>>> adj;
    for(auto it : edges)
    {
        int wt = it[2];
        int u = it[0];
        int v = it[1];

        adj.push_back({wt , {u , v}});
    }

    sort(adj.begin() , adj.end());

    DisjointSet ds(N);

    int ans = 0;
    for(auto it : adj)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findParent(u) != ds.findParent(v))
        {
            ans += wt;
            ds.unionByRank(u , v);
        }
    }
    return ans;
}