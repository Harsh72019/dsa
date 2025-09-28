#include<bits/stdc++.h>
using namespace std;

  bool isHeap(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        while(index < size)
        {
            int left = index * 2 + 1;
            int right = index * 2 + 2; 
            if(left < size && nums[left] < nums[index])
                return false;
            if(right < size && nums[right] < nums[index])
                return false;
            index++;
        }
        return true;
    }