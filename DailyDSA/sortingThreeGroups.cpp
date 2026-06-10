#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int dp1 = 0;
        int dp2 = 0;
        int dp3 = 0;

        for (int x : nums)
        {
            int ndp1 = dp1 + (x != 1);
            int ndp2 = min(dp1, dp2) + (x != 2);
            int ndp3 = min({dp1, dp2, dp3}) + (x != 3);

            dp1 = ndp1;
            dp2 = ndp2;
            dp3 = ndp3;
        }

        return min({dp1, dp2, dp3});
    }
};