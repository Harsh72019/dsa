#include <bits/stdc++.h>
using namespace std;

int findKthSmallest_MinHeap(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int num : nums)
        pq.push(num);

    for (int i = 1; i < k; ++i)
        pq.pop();

    return pq.top();
}
