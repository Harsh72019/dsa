#include<bits/stdc++.h>
using namespace std;


int solver(int index1 , int index2 , string& text1 , string& text2 , vector<vector<int>>& dp)
{
    if (index1 >= text2.size() || index2 >= text1.size()) {
        return 0;
    }
    if (dp[index1][index2] != -1) {
        return dp[index1][index2];
    }
    if(text1[index1] == text2[index2])
    {
        return dp[index1][index2] = 1 + solver(index1 + 1, index2 + 1 , text1 , text2 , dp);
    }
    return dp[index1][index2] = max(solver(index1 + 1 , index2 , text1 , text2 , dp) , solver(index1 , index2 + 1 , text1 , text2 , dp));
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n +1 , vector<int>(m + 1 , -1));
    return solver(0, 0, text1, text2 , dp);
}