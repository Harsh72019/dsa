#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums, int m, int threshold) {
    int sum = 0;
    for (int i : nums) {
        sum += (i + m - 1) / m; 
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;  
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(nums, mid, threshold)) {
            ans = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;
        }
    }
    return ans;
}