#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;
    void dfs(int node , int parent , vector<bool> & visited , vector<vector<int>>& adj , vector<int>& tin , vector<int>& low , vector<vector<int>> & bridges)
    {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node])
        {
            if(it == parent)   continue;
            if(!visited[it])
            {
                dfs(it , node , visited , adj , tin , low , bridges);
                low[node] =min(low[node] , low[it]);
                if(low[it] > tin[node])
                {
                    bridges.push_back({it , node});
                }

            }
            else
            {
                low[node] =min(low[node] , low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> tin(n);
        vector<int> low(n);
        vector<bool> visited(n ,false);
        vector<vector<int>> ciritalPoints;
        dfs(0 , -1 , visited , adj , tin , low , ciritalPoints);
        return ciritalPoints;

    }
};