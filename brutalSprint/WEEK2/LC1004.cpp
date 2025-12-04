#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int numOfZeros = 0;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            numOfZeros++;
        while (numOfZeros > k)
        {
            if (nums[left] == 0)
                numOfZeros--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}