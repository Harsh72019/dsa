#include<bits/stdc++.h>
using namespace std;


void solve(int index , vector<int>& candidates , int target , vector<vector<int>>& ans , vector<int> & subAns)
{
    if(target == 0)
    {
        ans.push_back(subAns);
        return;
    }
    for(int i = index ; i < candidates.size() ; i++)
    {
        if(i > index && candidates[i] == candidates[i-1]) continue;
        if(candidates[i] > target) break;
        subAns.push_back(candidates[i]);
        solve(i + 1,  candidates, target - candidates[i] , ans , subAns);
        subAns.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    vector<vector<int>> ans;
    vector<int> subAns;
    solve(0 , candidates , target , ans , subAns);
    return ans;
}