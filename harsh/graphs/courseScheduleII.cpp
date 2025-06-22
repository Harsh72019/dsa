#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited, stack<int> &st)
{
    visited[node] = true;
    pathVisited[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (dfs(it, adj, visited, pathVisited, st))
                return true;
        }
        else if (pathVisited[it])
        {
            return true;
        }
    }

    pathVisited[node] = false;
    st.push(node);
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> visited(numCourses, false);
    vector<bool> pathVisited(numCourses, false);
    stack<int> st;

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited, st))
            {
                return {};
            }
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}