#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    map<char, int> mp;
    int n = s.size();
    for (char c : s)
    {
        mp[c]++;
        if (mp[c] > (n + 1) / 2)
            return "";
    }
    priority_queue<pair<int, char>> pq;
    for (auto p : mp)
    {
        pq.push({p.second, p.first});
    }
    string ans;
    while (pq.size() >= 2)
    {
        auto [f1, c1] = pq.top();
        pq.pop();
        auto [f2, c2] = pq.top();
        pq.pop();
        ans += c1;
        ans += c2;
        f1--;
        f2--;
        if (f1 > 0)
            pq.push({f1, c1});
        if (f2 > 0)
            pq.push({f2, c2});
    }
    if (!pq.empty())
        ans += pq.top().second;

    return ans;
}