#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    for(int i = 1 ; i < numRows ; i++)
    {
        vector<int> subAns;
        for(int j = 0 ; j <= i ; j++)
        {
            if(j == 0 || j == i)
                subAns.push_back(1);
            else
                subAns.push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        ans.push_back(subAns);
    }
    return ans;
}