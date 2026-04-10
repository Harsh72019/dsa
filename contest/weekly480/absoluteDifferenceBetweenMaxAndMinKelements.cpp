#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        priority_queue<int , vector<int> , greater<int>> minHeap;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
            if(maxHeap.size() > k)
                maxHeap.pop();
            if(minHeap.size() > k)
                minHeap.pop();
        }

        int maxx = 0;
        int mins = 0;
        while(k != 0)
        {
            if(!maxHeap.empty())
            {
                mins += maxHeap.top();
                maxHeap.pop();
            }
            if(!minHeap.empty())
            {
                maxx += minHeap.top();
                minHeap.pop();
            }
            k--;
        }
        return (int)abs(mins - maxx);
    }
};