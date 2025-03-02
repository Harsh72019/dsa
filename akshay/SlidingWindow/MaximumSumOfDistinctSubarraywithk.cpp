// 2461. Maximum Sum of Distinct Subarrays With Length K
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            long long maxSum = 0, sum = 0;
            unordered_map<int, int> mp;  // Use unordered_map for O(1) lookup
            int i = 0, j = 0;
    
            while (j < nums.size()) {
                mp[nums[j]]++; 
                sum += nums[j]; 
    
                // If a duplicate appears, remove elements from the left
                while (mp[nums[j]] > 1) {
                    mp[nums[i]]--;
                    sum -= nums[i];
                    if (mp[nums[i]] == 0) mp.erase(nums[i]); // Remove key if count becomes zero
                    i++;
                }
    
                // When we have exactly `k` elements, check for max sum
                if (j - i + 1 == k) {
                    maxSum = max(maxSum, sum);
    
                    // Slide the window by removing the leftmost element
                    mp[nums[i]]--;
                    sum -= nums[i];
                    if (mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
    
                j++;  // Expand the window
            }
    
            return maxSum;
        }
    };