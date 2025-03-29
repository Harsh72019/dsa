#include<bits/stdc++.h>
using namespace std;

// Kadanes algorithm

int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int currentSum = 0;
    for(auto i : nums)
    {
     currentSum += i;
     ans = max(ans , currentSum);
     if(currentSum < 0)
         currentSum = 0;
    }
    return ans;
 }