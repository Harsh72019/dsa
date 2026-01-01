#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    priority_queue<int> maxHeap;

    int fuel = startFuel;
    int prevPos = 0;
    int stops = 0;
    int i = 0;

    while (prevPos < target)
    {
        // Add all reachable stations
        while (i < stations.size() && stations[i][0] <= prevPos + fuel)
        {
            maxHeap.push(stations[i][1]);
            i++;
        }

        // If we can reach target
        if (prevPos + fuel >= target)
            return stops;

        // No station to refuel from
        if (maxHeap.empty())
            return -1;

        // Refuel from the largest available station
        fuel += maxHeap.top();
        maxHeap.pop();
        stops++;
    }

    return stops;
}
