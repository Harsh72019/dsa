#include<bits/stdc++.h>
using namespace std;

    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int , int>>> adj(n);
        
        for(auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v , t});
            adj[v].push_back({u , t}); 
        }

        vector<long long> minTime(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long , int>, vector<pair<long long , int>>, greater<>> pq;
        pq.push({0 , 0});
        minTime[0] = 0;
        ways[0] = 1; 

        while(!pq.empty()) {
            long long currentTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                long long newTime = currentTime + it.second;
                int newNode = it.first;

                if(newTime < minTime[newNode]) {
                    minTime[newNode] = newTime;
                    ways[newNode] = ways[node];
                    pq.push({newTime , newNode});
                } else if(newTime == minTime[newNode]) {
                    ways[newNode] = (ways[newNode] + ways[node]) % MOD; 
                }
            }
        }

        return ways[n - 1];
    }
