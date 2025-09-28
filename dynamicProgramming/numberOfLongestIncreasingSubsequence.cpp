#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> size (n, 1), freq(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] && size[i] == 1 + size[j]) freq[i] += freq[j];
                else if(nums[i]>nums[j] && 1+size[j]>size[i]){
                    size[i] = 1 + size[j];
                    freq[i] = freq[j];
                }
            }
        }
        int maxSize = *max_element(size.begin(), size.end());
        int ans = 0; 
        for(int i=0; i<n; i++){
            if(size[i] == maxSize) ans += freq[i];
        }
        return ans;
    } 