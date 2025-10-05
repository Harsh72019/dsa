#include <bits/stdc++.h>
using namespace std;

bool allZero(vector<int> &match)
{
    for (int val : match)
        if (val != 0)
            return false;
    return true;
}

bool checkInclusion(string s1, string s2)
{
    if (s1 == s2)
        return true;

    int n = s1.size(), m = s2.size();
    if (n > m)
        return false;

    vector<int> match(26, 0);
    for (char c : s1)
        match[c - 'a']++;

    for (int i = 0; i < n; i++)
        match[s2[i] - 'a']--;

    if (allZero(match))
        return true;

    for (int i = n; i < m; i++)
    {
        match[s2[i - n] - 'a']++;
        match[s2[i] - 'a']--;
        if (allZero(match))
            return true;
    }
    return false;
}