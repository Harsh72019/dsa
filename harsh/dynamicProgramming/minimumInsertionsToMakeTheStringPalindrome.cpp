#include<bits/stdc++.h>
using namespace std;

 int solver(int left , int right , string& s , vector<vector<int>>& dp)
    {
        if(left > right) return 0;
        if(left == right) return 1;
        if(dp[left][right] != -1)   return dp[left][right];
        if(s[left] == s[right])
        {
            return dp[left][right] = 2 + solver(left + 1 , right - 1 , s , dp);
        }
        else{
            return dp[left][right] = max(solver(left + 1 , right  , s , dp) , solver(left , right - 1 , s , dp));
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return s.size() - solver(0, n - 1, s, dp);
    }