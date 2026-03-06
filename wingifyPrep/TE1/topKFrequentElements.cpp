#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> distinctCount;
    for (int i : nums)
    {
        distinctCount[i]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto ele : distinctCount)
    {
        minHeap.push({ele.second, ele.first});
        if (minHeap.size() > k)
            minHeap.pop();
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}