#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums , int goal){
    int ans = 0 ;
    int prefixSum = 0;
    unordered_map<int, int> um;
    for(int i = 0 ; i < nums.size() ; i++){
        prefixSum += nums[i];
        if(um.find(prefixSum - goal) != um.end())
        {
            ans += um[prefixSum - goal];
        }
        um[prefixSum]++;
    }
    return ans;
}