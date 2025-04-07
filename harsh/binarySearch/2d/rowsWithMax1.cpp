#include<bits/stdc++.h>
using namespace std;


  int lowerBound(vector<int>& arr, int target) {
            int ans = -1;
            int low = 0, high = arr.size() - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(arr[mid] >= target) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        }
        
        int rowWithMax1s(vector<vector<int>> &arr) {
            int maxOnes = 0;
            int ansRow = -1;
            int n = arr.size();
            int m = arr[0].size();
        
            for(int i = 0; i < n; ++i) {
                int lb = lowerBound(arr[i], 1);
                if(lb != -1) {
                    int ones = m - lb;
                    if(ones > maxOnes) {
                        maxOnes = ones;
                        ansRow = i;
                    }
                }
            }
        
            return ansRow;
        }