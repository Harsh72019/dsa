#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> previousElements;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int compliment = target - nums[i];
            if(previousElements.find(compliment) != previousElements.end())
                return {previousElements[compliment] , i };   
            previousElements[nums[i]] = i;
        }
        return { -1 , -1 };
    }