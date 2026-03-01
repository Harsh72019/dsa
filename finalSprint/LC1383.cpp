#include <bits/stdc++.h>
using namespace std;

int maxPerformance(int n,
                   vector<int> &speed,
                   vector<int> &efficiency,
                   int k)
{

    const int MOD = 1e9 + 7;

    vector<pair<int, int>> engineers;

    for (int i = 0; i < n; i++)
        engineers.push_back({efficiency[i], speed[i]});

    sort(engineers.rbegin(), engineers.rend());

    priority_queue<int, vector<int>, greater<int>> minHeap;

    long long speedSum = 0;
    long long maxPerf = 0;

    for (auto &e : engineers)
    {

        int currEff = e.first;
        int currSpeed = e.second;

        minHeap.push(currSpeed);
        speedSum += currSpeed;

        if (minHeap.size() > k)
        {
            speedSum -= minHeap.top();
            minHeap.pop();
        }

        maxPerf = max(maxPerf, speedSum * currEff);
    }

    return maxPerf % MOD;
}