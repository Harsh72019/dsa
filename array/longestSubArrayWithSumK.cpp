#include<bits/stdc++.h>
using namespace std;


int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> um;
    um[0] = -1;  
    int prefixSum = 0;
    int ans = 0; 

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        int compliment = prefixSum - k;
        if (um.find(compliment) != um.end()) {
            ans = max(ans, i - um[compliment]);
        }

        if (um.find(prefixSum) == um.end()) {
            um[prefixSum] = i;
        }
    }
    return ans;
}