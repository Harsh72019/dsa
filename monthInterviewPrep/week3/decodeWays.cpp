#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solver(string s , int index , vector<int>& dp)
    {
        if(index == s.size())
            return 1;

        if(s[index] == '0')
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int solo = solver(s , index + 1 , dp);

        int noSolo = 0;

        if(index + 1 < s.size())
        {
            string curr = "";
            curr += s[index];
            curr += s[index + 1];

            int num = stoi(curr);

            if(num >= 10 && num <= 26)
                noSolo = solver(s , index + 2 , dp);
        }

        return dp[index] = solo + noSolo;
    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n , -1);

        return solver(s , 0 , dp);
    }
};