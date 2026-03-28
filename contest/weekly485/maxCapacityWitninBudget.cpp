#include<bits/stdc++.h>
using namespace std;


class Solution {

    int binarySearch(vector<pair<int, int>> &a, int remaining, int high) {
        int low = 0;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid].first < remaining) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }

public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {costs[i], capacity[i]};
        }

        sort(a.begin(), a.end());

        int ans = 0;

        for (int i = 0; i < n && budget > a[i].first; i++) {
            int curr = a[i].second;
            if (i > 0)
                a[i].second = max(a[i].second, a[i - 1].second);
            
            int j = binarySearch(a, budget - a[i].first, i - 1);

            if (j != -1)
                curr += a[j].second;
            
            ans = max(ans, curr);
        }

        return ans;
    }
};
