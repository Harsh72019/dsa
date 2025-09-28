#include <bits/stdc++.h>
using namespace std;

int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
{
    int N = languages.size();

    vector<unordered_set<int>> langSet(N + 1);
    for (int i = 0; i < N; i++)
    {
        for (int lang : languages[i])
        {
            langSet[i + 1].insert(lang);
        }
    }

    unordered_set<int> candidates;
    for (auto &f : friendships)
    {
        int u = f[0], v = f[1];
        bool canCommunicate = false;

        for (int lang : langSet[u])
        {
            if (langSet[v].count(lang))
            {
                canCommunicate = true;
                break;
            }
        }
        if (!canCommunicate)
        {
            candidates.insert(u);
            candidates.insert(v);
        }
    }

    if (candidates.empty())
        return 0;

    int ans = INT_MAX;
    for (int lang = 1; lang <= n; lang++)
    {
        int cnt = 0;
        for (int person : candidates)
        {
            if (langSet[person].count(lang))
                cnt++;
        }
        ans = min(ans, (int)candidates.size() - cnt);
    }

    return ans;
}