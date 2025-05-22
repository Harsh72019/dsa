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

// More better approach


int funct(vector<int>& nums, int goal ){
        int i=0 ,j=0 , count=0 ,sum=0;
        while(j<nums.size()){
            if(goal<0)return 0;
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            count+=j-i+1;
            j++;
             }
             return count;
             }
    int numSubarraysWithSumBetter(vector<int>& nums, int sum) {
        return funct(nums , sum )-funct(nums  , sum-1);
     
    }