#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int>& weights, int days) {
    int currentWeight = 0, dayCount = 1;

    for (int weight : weights) {
        if (currentWeight + weight > mid) {
            dayCount++;
            currentWeight = 0;
        }
        currentWeight += weight;
        if (dayCount > days) return false;
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());  
    int high = accumulate(weights.begin(), weights.end(), 0); 
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, weights, days)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}