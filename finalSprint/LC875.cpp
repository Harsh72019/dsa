#include<bits/stdc++.h>
using namespace std;

 bool check(vector<int>& piles, int h, int k) {
        long long total = 0;
        for (int p : piles) {
            total += (p + k - 1) / k;
            if (total > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }