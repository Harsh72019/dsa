#include <bits/stdc++.h>
using namespace std;

int minOperations(string s)
{
    int ans = 0;
    for (char c : s)
    {
        int dist = (26 - (c - 'a')) % 26;
        ans = max(ans, dist);
    }
    return ans;
}