#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int , int> freq;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!(nums[i] % 2))
                freq[nums[i]]++;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(!(nums[i] % 2) && freq[nums[i]] == 1)
                return nums[i];  
        }
        return -1;
    }
};