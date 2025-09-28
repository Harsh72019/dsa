#include<bits/stdc++.h>
using namespace std;

// Kahn's Algorithm is just a topological Sorting algorithm that uses BFS.
vector<int> kahnsAlgorithm(int n, vector<vector<int>> &adj){
    vector<int> inDegree(n , 0);

    for(int i = 0 ; i < n ; i++)
    {
        for(auto it : adj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0 ; i < n ; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topoSort;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it : adj[node])
        {
            inDegree[it]--;
            if(inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return topoSort;
}