#include<bits/stdc++.h>
using namespace std;

 int minimumMultiplications(vector<int> &arr, int start, int end) {
        const int MOD = 100000;
        vector<int> visited(MOD, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, start});
        visited[start] = 1;

        while (!pq.empty()) {
           int steps  = pq.top().first;
           int value = pq.top().second;
            pq.pop();

            if (value == end) return steps;

            for (int num : arr) {
                int newValue = (value * num) % MOD;
                if (!visited[newValue]) {
                    visited[newValue] = 1;
                    pq.push({steps + 1, newValue});
                }
            }
        }

        return -1;
    }