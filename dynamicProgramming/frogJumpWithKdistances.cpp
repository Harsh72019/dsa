#include<bits/stdc++.h>
using namespace std;

int solver(vector<int>& heights , int k , int index , vector<int> & dp)
    {
        if(index == 0)  return 0;
        if(dp[index] != -1)  return dp[index];
        int ans = INT_MAX;
        for(int i = 1 ; i <= k; i++)
        {
            if(index - i >= 0)
            {
                int curr = solver(heights , k , index - i , dp) + abs(heights[index] -  heights[index - i]);
                ans = min (ans , curr);
            } 
        } 
        return dp[index] = ans;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n , -1);
        return solver(heights , k  , n - 1 , dp);
    }