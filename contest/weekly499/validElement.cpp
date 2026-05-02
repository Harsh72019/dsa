#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> greaters(n , -1);
        int currMax = -1;
        for(int i = n - 1; i >= 0 ; i--)
        {
            greaters[i] = currMax;
            currMax = max(currMax , nums[i]);
        }
        int lMax = -1;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(lMax < nums[i] || greaters[i] < nums[i])
                ans.push_back(nums[i]);
            lMax = max(lMax , nums[i]);
        }
        return ans;
    }
};