#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string str;
    int dp[2501][2501];
    int solve(int l, int r)
    {
        if(l>=r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        if(str[l]==str[r]) //normal palindrome just continue
            return dp[l][r]=solve(l+1,r-1);

        return dp[l][r]=1 + min(solve(l+1,r),solve(l,r-1));
    }
    int almostPalindromic(string s) {

        int n = s.size();
        memset(dp,-1,sizeof(dp));
        str=s;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
                {
                    int len = j-i+1;

                    if(len>=2 && solve(i,j)<=1){
                        ans = max(ans,len);
                    }
                }
        }

        return ans;
    }
};