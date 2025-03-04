#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int day, int k, int m) {
    int counter = 0;
    int ans = 0;
    for (auto i : arr) {
        if (i <= day) {
            counter++;
            if (counter == k) {
                ans++;
                counter = 0; 
            }
        } else {
            counter = 0;
        }
    }
    return ans >= m; 
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if ((long long)m * k > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(bloomDay, mid, k, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}