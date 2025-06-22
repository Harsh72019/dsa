#include<bits/stdc++.h>
using namespace std;


 bool dfs(int node ,  vector<vector<int>>& adj , vector<bool> & visited , vector<bool> & pathVisited)
    {
        visited[node] = true;
        pathVisited[node] = true;

        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it , adj , visited , pathVisited))   return true;
            }
            else if(pathVisited[it])    return true;
        }
        pathVisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i  = 0 ;i < prerequisites.size() ; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> pathVisited(numCourses , false);
        vector<bool> visited(numCourses , false);

        for(int i = 0 ;i <numCourses ; i++)
        {
            if(dfs(i , adj , visited , pathVisited))  return false;
        }

        return true;
    }