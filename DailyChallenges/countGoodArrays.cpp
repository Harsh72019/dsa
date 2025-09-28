#include<bits/stdc++.h>
using namespace std;


long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0;
    long long ans = 0;
    unordered_map<int , int> um;
    long long pairCounter = 0;

    for (int j = 0; j < n; j++) {
        pairCounter += um[nums[j]];  
        um[nums[j]]++;

        while (pairCounter >= k) {
            ans += n - j;  
            pairCounter -= um[nums[i]] - 1;  
            um[nums[i]]--;
            i++;
        }
    }
    return ans;
}