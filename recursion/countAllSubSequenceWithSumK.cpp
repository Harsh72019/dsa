#include<bits/stdc++.h>
using namespace std;

int solve(int index, vector<int>& nums, int sum, int k) {
    if (index == nums.size()) {
        return sum == k ? 1 : 0;
    }

    int take = solve(index + 1, nums, sum + nums[index], k);

    int notTake = solve(index + 1, nums, sum, k);

    return take + notTake;
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
    return solve(0, nums, 0, k);
}