#include <bits/stdc++.h>
using namespace std;

// My original approach
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < nums.size() && j < nums.size())
    {
        while (i < nums.size() && nums[i] < 0)
            i++;
        ans.push_back(nums[i]);
        while (j < nums.size() && nums[j] >= 0)
            j++;
        ans.push_back(nums[j]);
        i++;
        j++;
    }
    return ans;
}

//  A more cleaner code
vector<int> rearrangeArray2(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    int positiveIndex = 0;
    int negativeIndex = 1;
    for (auto i : nums)
    {
        if (i >= 0)
        {
            ans[positiveIndex] = i;
            positiveIndex = positiveIndex + 2;
        }
        else
        {
            ans[negativeIndex] = i;
            negativeIndex = negativeIndex + 2;
        }
    }
    return ans;
}