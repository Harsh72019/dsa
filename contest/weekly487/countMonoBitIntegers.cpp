#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMonobit(int n)
    {
        int ans = 1;
        int v = 1;
        while (v <= n)
        {
            v = v << 1 | 1;
            ans++;
        }

        return ans;
    }
};