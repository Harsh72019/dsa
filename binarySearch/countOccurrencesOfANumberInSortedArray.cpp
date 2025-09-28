#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


int countFreq(vector<int>& arr, int target) {
    int startIndex = lowerBound(arr  , target);
    int endIndex = upperBound(arr , target);
    return endIndex - startIndex;
}