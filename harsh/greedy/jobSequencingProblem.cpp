#include<bits/stdc++.h>
using namespace std;


vector<int> JobScheduling(vector<vector<int>>& Jobs) {
    sort(Jobs.begin() , Jobs.end() , [](vector<int> &a , vector<int> &b){return a[1] > b[1];});
    int n = Jobs.size();
    
    int maxDeadline = 0;
    for(auto job : Jobs)
    {
        maxDeadline = max(maxDeadline, job[1]);
    }

    vector<bool> ans(maxDeadline + 1 , false);
    
    int totalJobs = 0;
    int totalProfit = 0;

    for(auto job : Jobs)
    {
        int deadline = job[1];
        int profit = job[2];

        for(int d = deadline ; d > 0 ; d--)
        {
            if(ans[d] == false)
            {
                ans[d] = true;
                totalJobs++;
                totalProfit += profit;
                break;
            }
        }
    }
    return {totalJobs , totalProfit};
}