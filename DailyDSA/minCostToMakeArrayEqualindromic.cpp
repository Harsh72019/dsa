#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(long long x)
    {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }

    long long getCost(vector<int> &nums, long long target)
    {
        long long cost = 0;
        for (int x : nums)
        {
            cost += llabs((long long)x - target);
        }
        return cost;
    }

    long long minimumCost(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        long long median = nums[nums.size() / 2];

        long long leftPal = median;
        while (leftPal > 0 && !isPalindrome(leftPal))
            leftPal--;

        long long rightPal = median;
        while (!isPalindrome(rightPal))
            rightPal++;

        return min(
            getCost(nums, leftPal),
            getCost(nums, rightPal));
    }
};