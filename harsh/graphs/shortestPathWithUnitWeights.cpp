#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
      vector<vector<int>> adj(N);
      for(auto it : edges)
      {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }

      queue<pair<int , int>> q;
      q.push({0 , 0});
      vector<bool> visited(N , false);
      vector<int> ans(N , INT_MAX);
      while(!q.empty())
      {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        ans[node] = min(ans[node] , distance);

        for(auto it: adj[node])
        {
          if(!visited[it])
          {
            visited[it] = true;
            q.push({it , distance + 1});
          }
        }
      }
      return ans;
    } 