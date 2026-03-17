#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char notC(char i)
    {
        return i == '1' ? '0' : '1';
    }
    string maximumXor(string s, string t)
    {
        unordered_map<char, int> binary;
        for (char it : t)
        {
            binary[it]++;
        }
        string ans = "";
        for (char it : s)
        {
            char opp = notC(it);
            if (binary[opp] != 0)
            {
                ans += "1";
                binary[opp]--;
            }
            else
            {
                ans += "0";
            }
        }
        return ans;
    }
};