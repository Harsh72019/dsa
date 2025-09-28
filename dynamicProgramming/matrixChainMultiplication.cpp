#include<bits/stdc++.h>
using namespace std;


int solver(int i , int j , vector<int>& arr ,vector<vector<int>> & dp)
{
    if(i == j )
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for(int k = 0 ; k <= j ; k++)
    {
        int steps = solver(i , k , arr , dp) + solver(k + 1 , j , arr  , dp) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans , steps);
    }
    return  dp[i][j] = ans;
}

int mcm(vector<int>& arr)
{
    int n = arr.size() - 1;
    vector<vector<int>> dp(n , vector<int>(n , -1));
    return solver(1 , n , arr , dp);
}