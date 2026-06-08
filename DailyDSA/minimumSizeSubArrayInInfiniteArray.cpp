#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();

        auto shortestWindow = [&](long long need) -> long long {
            if (need == 0) return 0;

            vector<int> arr;
            arr.reserve(2 * n);

            for (int x : nums) arr.push_back(x);
            for (int x : nums) arr.push_back(x);

            long long sum = 0;
            long long ans = LLONG_MAX;
            int l = 0;

            for (int r = 0; r < 2 * n; r++) {
                sum += arr[r];

                while (l <= r && sum > need) {
                    sum -= arr[l++];
                }

                if (sum == need) {
                    ans = min(ans, (long long)(r - l + 1));
                }
            }

            return ans;
        };

        long long k = target / total;
        long long rem = target % total;

        long long ans = LLONG_MAX;

        long long len1 = shortestWindow(rem);
        if (len1 != LLONG_MAX) {
            ans = min(ans, k * n + len1);
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};