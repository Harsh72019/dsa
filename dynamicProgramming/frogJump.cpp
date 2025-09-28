#include<bits/stdc++.h>
using namespace std;

int solver(vector<int> & heights , int index,  vector<int>& dp)
{
    if(index == 0)  return 0;
    if(dp[index] != -1)    return dp[index];
    int oneStep = solver(heights , index - 1 , dp) + abs(heights[index] - heights[index - 1]);
    int twoStep = INT_MAX;

    if(index > 1) twoStep = solver(heights , index - 2 , dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] =  min(oneStep , twoStep);

}

// heights = [2, 1, 3, 5, 4]
int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n , -1);
        return solver(heights , n -1 , dp);
}