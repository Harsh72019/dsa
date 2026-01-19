#include<bits/stdc++.h>
using namespace std;


vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> W(n - k + 1, 0);
        W[0] = accumulate(nums.begin(), nums.begin() + k, 0);

        for (int i = 1; i < W.size(); i++) {
            W[i] = W[i - 1] - nums[i - 1] + nums[i + k - 1];
        }

        int m = W.size();

        vector<int> bestLeftSumIdx(m, 0);
        for (int i = 1; i < m; i++) {
            if (W[i] > W[bestLeftSumIdx[i - 1]])
                bestLeftSumIdx[i] = i;
            else
                bestLeftSumIdx[i] = bestLeftSumIdx[i - 1];
        }

        vector<int> bestRightSumIdx(m, m - 1);
        for (int i = m - 2; i >= 0; i--) {
            if (W[i] >= W[bestRightSumIdx[i + 1]])
                bestRightSumIdx[i] = i;
            else
                bestRightSumIdx[i] = bestRightSumIdx[i + 1];
        }

        vector<int> ans(3, 0);
        int maxSum = 0;

        for (int j = k; j <= m - k - 1; j++) {
            int left = bestLeftSumIdx[j - k];
            int right = bestRightSumIdx[j + k];

            int total = W[left] + W[j] + W[right];

            if (total > maxSum) {
                maxSum = total;
                ans = {left, j, right};
            }
        }

        return ans;
    }