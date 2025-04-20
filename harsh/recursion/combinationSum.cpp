#include<bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>& nums, int sum, int k, vector<int>& subAns, vector<vector<int>>& ans) {
    if (sum == k) {
        ans.push_back(subAns);
        return;
    }
    if (sum > k || index == nums.size()) {
        return;
    }

    
    subAns.push_back(nums[index]);
    solve(index , nums, sum + nums[index], k, subAns, ans);
    subAns.pop_back();  

    solve(index + 1, nums, sum, k, subAns, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> subAns;
    vector<vector<int>> ans;
    solve(0, candidates, 0, target, subAns, ans);
    return ans;
}