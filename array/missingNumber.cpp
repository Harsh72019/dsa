#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    for(int i = 0 ; i < nums.size() ; i ++){
        while(nums[i] != i && nums[i] < nums.size())
        {
            swap(nums[i] , nums[nums[i] == nums.size() ? nums[i] -1 : nums[i]]);
        }
    }
    for(int i =  0 ; i < nums.size() ; i++){
        if(nums[i] != i)
            return i;
    }
    return nums.size();
}