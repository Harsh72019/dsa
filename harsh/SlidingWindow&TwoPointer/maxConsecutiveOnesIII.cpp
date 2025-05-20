#include<bits/stdc++.h>
using namespace std;

 int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int currentWindowSize = 0;
        int maxSize = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 1) {
                currentWindowSize++;
            } else if (nums[end] == 0 && k > 0) {
                k--;
                currentWindowSize++;
            } else {
                while (k == 0 && start <= end) {
                    if (nums[start] == 0)
                        k++;
                    currentWindowSize--;
                    start++;
                }
                k--;
                currentWindowSize++;
            }
            maxSize = max(maxSize, currentWindowSize);
        }
        return maxSize;
    }