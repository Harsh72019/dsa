#include<bits/stdc++.h>
using namespace std;

long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!st.empty() && st.top().first > arr[i]) {
                count += st.top().second;
                st.pop();
            }
            left[i] = count;
            st.push({arr[i], count});
        }

        st = stack<pair<int, int>>(); 

        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!st.empty() && st.top().first >= arr[i]) {
                count += st.top().second;
                st.pop();
            }
            right[i] = count;
            st.push({arr[i], count});
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)arr[i] * left[i] * right[i]);
        }

        return res;
    }

      long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!st.empty() && st.top().first < arr[i]) {
                count += st.top().second;
                st.pop();
            }
            left[i] = count;
            st.push({arr[i], count});
        }

        st = stack<pair<int, int>>(); 

        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!st.empty() && st.top().first <= arr[i]) {
                count += st.top().second;
                st.pop();
            }
            right[i] = count;
            st.push({arr[i], count});
        }

        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)arr[i] * left[i] * right[i]);
        }

        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mins =    sumSubarrayMins(nums);
        long long maxs = sumSubarrayMaxs(nums);
        return maxs - mins;
    }