#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> um;
    for (auto i : strs)
    {
        string original = i;
        sort(i.begin(), i.end());
        um[i].push_back(original);
    }
    vector<vector<string>> ans;
    for (auto it : um)
    {
        ans.push_back(it.second);
    }
    return ans;
}