#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countWays(vector<int>& A, vector<int>& B) {
        unordered_map<long long, int> productFreq;

        int m = B.size();

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                productFreq[1LL * B[i] * B[j]]++;
            }
        }

        long long ans = 0;

        for (int x : A) {
            ans += productFreq[1LL * x * x];
        }

        return ans;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return countWays(nums1, nums2) + countWays(nums2, nums1);
    }
};