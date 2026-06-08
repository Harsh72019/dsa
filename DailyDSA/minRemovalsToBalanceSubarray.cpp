#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0;
        int best = 1;

        for (int r = 0; r < n; r++) {
            while (1LL * nums[r] > 1LL * nums[l] * k) {
                l++;
            }

            best = max(best, r - l + 1);
        }

        return n - best;
    }
};