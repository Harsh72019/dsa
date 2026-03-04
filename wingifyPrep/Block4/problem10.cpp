#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<int> &startTimes, vector<int> &endTimes)
    {
        int n = startTimes.size();
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
};
