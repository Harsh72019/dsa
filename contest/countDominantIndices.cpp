#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        // int sum = 0;
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int ans = 0;
        int average;
        for(int i = 0 ; i < n -1 ; i++)
        {
            sum  -= nums[i];
            average = sum / (n - i - 1);
            if(average < nums[i])
                ans++;
        }
        return ans;
    }
};