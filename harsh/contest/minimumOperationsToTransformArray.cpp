#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums)
{
    return count(nums.begin(), nums.end(), nums[0]) != nums.size();
}