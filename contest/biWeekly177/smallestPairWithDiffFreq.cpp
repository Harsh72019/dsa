#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string mergeCharacters(string s, int k)
    {
        unordered_map<char, int> ind;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            bool canPush = false;

            if (ind.find(s[i]) == ind.end())
            {
                canPush = true;
            }
            else
            {
                int distance = ans.size() - ind[s[i]];
                if (distance > k)
                    canPush = true;
            }

            if (canPush)
            {
                ans += s[i];
                ind[s[i]] = ans.size() - 1;
            }
        }

        return ans;
    }
};