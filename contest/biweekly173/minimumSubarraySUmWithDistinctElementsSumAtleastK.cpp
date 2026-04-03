#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {
        int sum = 0;
        int ans = INT_MAX;
        unordered_map<int, int> um;

        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {

            // Add only if first occurrence
            if (um[nums[right]] == 0)
            {
                sum += nums[right];
            }
            um[nums[right]]++;

            while (left <= right && sum >= k)
            {
                ans = min(ans, right - left + 1);

                um[nums[left]]--;
                if (um[nums[left]] == 0)
                {
                    sum -= nums[left];
                }
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};