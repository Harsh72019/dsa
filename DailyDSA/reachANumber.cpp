#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);

        long long sum = 0;
        int step = 0;

        while (sum < target || (sum - target) % 2)
        {
            step++;
            sum += step;
        }

        return step;
    }
};