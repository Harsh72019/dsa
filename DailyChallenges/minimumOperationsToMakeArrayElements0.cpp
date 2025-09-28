#include <bits/stdc++.h>
using namespace std;

long long minOperations(vector<vector<int>> &queries)
{
    long long total = 0;
    for (auto &q : queries)
    {
        long long l = q[0];
        long long sum = 0, operations = 0;
        long long r = q[1];
        for (long long range = 1; range <= r; range *= 4)
        {
            long long sr = max(range, l);
            long long er = min(r, range * 4 - 1);
            sum += max(0LL, ++operations * (er - sr + 1));
        }
        total += (sum + 1) / 2;
    }
    return total;
}