#include <bits/stdc++.h>
using namespace std;

int minMachines(int n, vector<int> startTimes, vector<int> endTimes)
{
    vector<vector<int>> times(n);
    for (int i = 0; i < n; i++)
    {
        times[i] = {startTimes[i], endTimes[i]};
    }
    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto &t : times)
    {
        if (!minHeap.empty() && t[0] >= minHeap.top())
        {
            minHeap.pop();
        }
        minHeap.push(t[1]);
    }

    return minHeap.size();
}

int main()
{
    vector<int> startTimes = {7, 2, 5};
    vector<int> endTimes = {10, 4, 6};
    cout << minMachines(3, startTimes, endTimes);
    return 1;
}