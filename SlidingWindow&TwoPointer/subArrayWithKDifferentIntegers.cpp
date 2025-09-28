#include<bits/stdc++.h>
using namespace std;


 int atMostK(vector<int>& s, int k) {
        unordered_map<int, int> um;
        int start = 0;
        int ans = 0;

        for (int end = 0; end < s.size(); end++) {
            if (um[s[end]] == 0) k--;
            um[s[end]]++;

            while (k < 0) {
                um[s[start]]--;
                if (um[s[start]] == 0) {
                    um.erase(s[start]);
                    k++;
                }
                start++;
            }

            ans += end - start + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }