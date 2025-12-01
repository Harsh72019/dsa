#include<bits/stdc++.h>
using namespace std;

bool solver(vector<int>& nums, int index , int currentSum , int remainingSum , vector<vector<int>> & dp)
    {
        if(currentSum == remainingSum)
            return true;
        if(index >= nums.size())
            return false;
        if(dp[index][currentSum] != -1)
            return dp[index][currentSum];
        bool take = solver(nums , index + 1 , currentSum + nums[index] , remainingSum - nums[index] , dp);
        bool notTake = solver(nums , index + 1 , currentSum  , remainingSum , dp);
        return dp[index][currentSum] =  take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        
        int total = accumulate(nums.begin() , nums.end() , 0) ;
        vector<vector<int>> dp(nums.size() ,  vector<int>(total + 1 , -1));
        return solver(nums , 0 , 0 , total , dp);
    }