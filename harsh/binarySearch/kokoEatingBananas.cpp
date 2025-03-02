#include<bits/stdc++.h>
using namespace std;

bool canEatAll(vector<int>& piles, int k, int h) {
    long long hours = 0;
    for (int bananas : piles) {
        hours += (bananas + k - 1) / k;  
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxEle = *max_element(piles.begin(), piles.end());
    int low = 1, high = maxEle, ans = maxEle;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canEatAll(piles, mid, h)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}