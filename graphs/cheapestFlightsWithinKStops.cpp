#include<bits/stdc++.h>
using namespace std;


 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int N = flights.size();
        vector<vector<pair<int , int>>> adj(n);
        for(int i = 0 ; i < N ; i++) {
            int source = flights[i][0];
            int destination = flights[i][1];
            int cost = flights[i][2];
            adj[source].push_back({destination , cost});
        }

        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<> > pq;
        pq.push({0 , 0 , src});

        vector<int> minStops(n, INT_MAX);

        while(!pq.empty()) {
            auto [currentDistance, currentStops, currentNode] = pq.top();
            pq.pop();

            if (currentStops > minStops[currentNode]) continue;
            minStops[currentNode] = currentStops;

            if (currentNode == dst) return currentDistance;

            if(currentStops > k) continue;

            for(auto& it : adj[currentNode]) {
                int newNode = it.first;
                int newD = it.second;
                pq.push({currentDistance + newD, currentStops + 1, newNode});
            }
        }

        return -1;
    }