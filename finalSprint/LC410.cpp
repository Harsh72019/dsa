#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int currentSum = 0;
        int pieces = 1;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                pieces++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }

        return pieces <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};


class Solution {
public:
    int solver(int index,vector<int>& nums,int k , vector<vector<int>>& dp)
    {
        if (k == 0)
        {
            int sum = 0;
            for (int i = index; i < nums.size(); i++)
                sum += nums[i];
            return sum;
        }
        if(dp[index][k] != -1)
            return dp[index][k];
        int total = 0;
        int best = INT_MAX;

        for (int i = index; i <= nums.size() - k - 1; i++)
        {
            total += nums[i];

            int rest = solver(i + 1, nums, k - 1 , dp);

            int largest = max(total, rest);

            best = min(best, largest);
        }

        return dp[index][k] = best;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();       
        vector<vector<int>> dp(n,vector<int>(k , -1));
        return solver(0 , nums , k -1 , dp);
    }
};