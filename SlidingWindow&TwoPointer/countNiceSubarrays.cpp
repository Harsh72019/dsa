#include<bits/stdc++.h>
using namespace std;


int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int start = 0, count = 0;
        for (int end = 0; end < nums.size(); ++end) {
            if (nums[end] % 2 == 1)
                --k;
            
            while (k < 0) {
                if (nums[start] % 2 == 1)
                    ++k;
                ++start;
            }
            count += end - start + 1;
        }
        return count;
    }