#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, int> um;
    vector<vector<string>> ans;
    int index = 0;
    for (auto i : strs)
    {
        string s = i;
        sort(s.begin(), s.end());
        if (um.find(s) != um.end())
        {
            ans[um[s]].push_back(i);
        }
        else
        {
            um[s] = index;
            ans.push_back({i});
            index++;
        }
    }
    return ans;
}
