#include <bits/stdc++.h>
using namespace std;

int prefixConnected(vector<string> &words, int k)
{
    unordered_map<string, int> freq;
    for (string word : words)
    {
        if (word.size() < k)
            continue;
        string check = word.substr(0, k);
        freq[check]++;
    }
    int ans = 0;
    for (auto it : freq)
    {
        if (it.second > 1)
            ans++;
    }
    return ans;
}