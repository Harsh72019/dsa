#include<bits/stdc++.h>
using namespace std;

void solve(int index , vector<int>& nums , vector<vector<int>>& ans , vector<int>& curr)
    {
        if(index >= nums.size())
            return;

        curr.push_back(nums[index]);
        ans.push_back(curr);
        solve(index + 1 , nums  , ans , curr);
        curr.pop_back();

        solve(index + 1 , nums , ans , curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr ; 
        ans.push_back({});
        solve( 0 , nums , ans , curr);
        return ans;
    }