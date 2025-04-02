#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    for(int i  = 1; i <  n ; i ++)
    {
        if(nums[index] != nums[i])
            nums[++index] = nums[i];
    }
    return index + 1;
}