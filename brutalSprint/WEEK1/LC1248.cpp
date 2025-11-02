#include <bits/stdc++.h>
using namespace std;

bool isOdd(int n)
{
    if (n % 2 == 0)
        return false;
    return true;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    unordered_map<int, int> um;
    int oddNumbers = 0;
    int ans = 0;
    um[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (isOdd(nums[i]))
            oddNumbers += 1;
        int compliment = oddNumbers - k;
        if (um.find(compliment) != um.end())
            ans += um[compliment];
        um[oddNumbers]++;
    }
    return ans;
}