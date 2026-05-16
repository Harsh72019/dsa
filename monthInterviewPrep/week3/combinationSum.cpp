#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solver(vector<int> & candidates , int index , int target , vector<int>& subAns , vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(subAns);
            return;
        }
        if(index >= candidates.size())
            return;
        solver(candidates , index + 1 , target , subAns , ans);
        if(target - candidates[index] >= 0)
        {
            subAns.push_back(candidates[index]);
            solver(candidates , index , target - candidates[index], subAns , ans);
            subAns.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subAns;
        solver(candidates , 0 , target , subAns , ans);
        return ans;

    }
};