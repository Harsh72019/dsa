#include<bits/stdc++.h>
using namespace std;


string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n , vector<bool>(n, false));
    for(int i = 0 ; i < n ; i++) {
        dp[i][i] = true;
    }

    string ans = s.substr(0, 1);  

    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            if(2 > ans.size())
                ans = s.substr(i, 2);
        } else {
            dp[i][i + 1] = false;
        }
    }

    for(int i = n - 3; i >= 0; i--) {
        for(int j = i + 2; j < n; j++) {
            if(s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if(j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            } else {
                dp[i][j] = false;
            }
        }
    }

    return ans;
}