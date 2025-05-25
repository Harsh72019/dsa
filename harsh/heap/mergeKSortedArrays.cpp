#include<bits/stdc++.h>
using namespace std;


vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (const auto& array : arrays) {
        for (int num : array) {
            minHeap.push(num);
        }
    }
    
    vector<int> mergedArray;
    
    while (!minHeap.empty()) {
        mergedArray.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return mergedArray;
}