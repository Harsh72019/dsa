#include<bits/stdc++.h>
using namespace std;


int countPairs(vector<int>& nums, int k) {
    unordered_map<int  , vector<int>> um;
    int ans = 0;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(um.find(nums[i]) != um.end())
        {
            for(auto j : um[nums[i]])
            {
                if((i * j) % k == 0 )
                    ans++;
            }
        }
        um[nums[i]].push_back(i);
    }
    return ans;
}