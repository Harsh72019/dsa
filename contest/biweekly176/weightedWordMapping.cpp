#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateWeight(string word, vector<int> &weights)
    {
        int total = 0;
        for (auto it : word)
        {
            total += weights[it - 'a'];
        }
        return total % 26;
    }
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans = "";
        for (string word : words)
        {
            int wordWeight = calculateWeight(word, weights);
            int reverseNum = 122 - wordWeight;
            ans += (char)(reverseNum);
        }
        return ans;
    }
};