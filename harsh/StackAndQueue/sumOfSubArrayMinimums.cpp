#include<bits/stdc++.h>
using namespace std;


  int sumSubarrayMins(vector<int>& arr) {
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
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)arr[i] * left[i] * right[i]) % mod;
        }

        return (int)res;
    }