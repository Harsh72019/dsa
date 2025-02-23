#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int upperBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int lower = lowerBound(nums, target);
    int upper = upperBound(nums, target) - 1;
    if (lower < nums.size() && nums[lower] == target)
    {
        return {lower, upper};
    }
    return {-1, -1};
}
