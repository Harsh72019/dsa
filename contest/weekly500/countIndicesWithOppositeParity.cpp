#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countOppositeParity(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> suffixParity(n);
        int odds = 0;
        int evens = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            suffixParity[i] = {odds, evens};
            if (nums[i] % 2 == 0)
                evens++;
            else
                odds++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(suffixParity[i][nums[i] % 2]);
        }
        return ans;
    }
};