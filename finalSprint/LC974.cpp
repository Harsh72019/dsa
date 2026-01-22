#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1; 

    int sum = 0;
    int ans = 0;

    for (int x : nums)
    {
        sum += x;
        int rem = ((sum % k) + k) % k; 

        ans += freq[rem];
        freq[rem]++;
    }

    return ans;
}
