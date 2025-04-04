#include<bits/stdc++.h>
using namespace std;


bool isPossible(vector<int>& arr, int maxPages, int students) {
    int studentCount = 1;  
    int currentSum = 0;

    for (int pages : arr) {
        if (currentSum + pages > maxPages) {  
            studentCount++;
            currentSum = pages;  

            if (studentCount > students) return false;  
        } else {
            currentSum += pages;  
        }
    }
    return true;  
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;  

    int low = *max_element(arr.begin(), arr.end());  
    int high = accumulate(arr.begin(), arr.end(), 0); 
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isPossible(arr, mid, m)) {
            ans = mid;  
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


