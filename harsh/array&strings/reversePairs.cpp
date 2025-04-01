#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int low, int mid, int high) {
    int count = 0;
    int right = mid + 1;

    for (int left = low; left <= mid; left++) {
        while (right <= high && arr[left] > 2LL * arr[right]) {
            right++;
        }
        count += (right - (mid + 1)); 
    }

    return count;
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;
    
    int mid = low + (high - low) / 2;
    int count = 0;
    
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    
    merge(arr, low, mid, high);
    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}