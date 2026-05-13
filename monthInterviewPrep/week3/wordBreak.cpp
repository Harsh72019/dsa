#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool solver(string &s, vector<string>& wordDict, int sIndex, vector<int>& dp)
    {
        if(sIndex == s.size())
            return true;

        if(dp[sIndex] != -1)
            return dp[sIndex];

        for(int i = 0; i < wordDict.size(); i++)
        {
            int wordS = wordDict[i].size();

            if(sIndex + wordS > s.size())
                continue;

            string nWord = s.substr(sIndex, wordS);

            if(nWord == wordDict[i])
            {
                if(solver(s, wordDict, sIndex + wordS, dp))
                    return dp[sIndex] = true;
            }
        }

        return dp[sIndex] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), -1);

        return solver(s, wordDict, 0, dp);
    }
};