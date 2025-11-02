#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    if (nums.size() == 1)
        return true;
    int maxJump = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxJump = max(maxJump, i + nums[i]);
        if (maxJump == i && maxJump != nums.size() - 1)
            return false;
    }
    return true;
}