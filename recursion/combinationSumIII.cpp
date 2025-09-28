#include <bits/stdc++.h>
using namespace std;

void solve(int index, int toUse, int target, vector<int> &subAns, vector<vector<int>> &ans)
{
    if (toUse == 0 && target == 0)
    {
        ans.push_back(subAns);
        return;
    }
    if (index > 9 || toUse < 0 || target < 0) 
        return;

 
    subAns.push_back(index);
    solve(index + 1, toUse - 1, target - index, subAns, ans);
    subAns.pop_back();
    solve(index + 1, toUse, target, subAns, ans);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> subAns;
    solve(1, k, n, subAns, ans);
    return ans;
}
