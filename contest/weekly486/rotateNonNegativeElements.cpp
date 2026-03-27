#include <bits/stdc++.h>
using namespace std;

vector<int> rotateElements(vector<int> &nums, int k)
{
    if (k == 0)
        return nums;
    vector<int> positives;
    for (int i : nums)
    {
        if (i >= 0)
        {
            positives.push_back(i);
        }
    }
    int n = positives.size();
    if (n == 0)
        return nums;

    k = k % n;
    reverse(positives.begin(), positives.begin() + k);
    reverse(positives.begin() + k, positives.end());
    reverse(positives.begin(), positives.end());
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            nums[i] = positives[index];
            index++;
        }
    }
    return nums;
}