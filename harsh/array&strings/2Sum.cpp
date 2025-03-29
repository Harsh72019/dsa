#include<bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int , int> um;
    for(int i = 0  ; i < nums.size() ; i++)
    {
        int compliment = target - nums[i];
        if(um.find(compliment) != um.end())
        {
            return {um[compliment] , i};
        }
        um[nums[i]] = i;
    }
    return {-1 , -1};
}