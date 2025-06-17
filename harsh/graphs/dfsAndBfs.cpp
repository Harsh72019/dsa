#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> & graph , int source)
{
    queue<int> q;
    vector<bool> visited(graph.size() , false);
    q.push(source);
    visited[source] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i = 0; i < graph[node].size(); i++)
        {
            if(!visited[graph[node][i]])
            {
                q.push(graph[node][i]);
                visited[graph[node][i]] = true;
            }
        }
    }
}

void dfs(vector<vector<int>> & graph , int source, vector<bool> & visited)
{
    visited[source] = true;
    cout << source << " ";
    for(int i = 0; i < graph[source].size(); i++)
    {
        if(!visited[graph[source][i]])
        {
            dfs(graph, graph[source][i], visited);
        }
    }
}

int main()
{

    int n = 5; 
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {1, 2};


    cout << "BFS starting from node 0: ";
    bfs(graph, 0);
    cout << endl;

    vector<bool> visited(n, false);
    cout << "DFS starting from node 0: ";
    dfs(graph, 0, visited);
    cout << endl;

    return 0;
}