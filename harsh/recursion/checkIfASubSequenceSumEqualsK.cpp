#include<bits/stdc++.h>
using namespace std;


bool solve(int index, vector<int>& nums, int sum, int k) {
    if (index == nums.size()) {
        return sum == k;
    }

    if (solve(index + 1, nums, sum + nums[index], k)) return true;
    if (solve(index + 1, nums, sum, k)) return true;

    return false;
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    return solve(0, nums, 0, k);
}