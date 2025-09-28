#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    // Traverse the array twice for circularity
    for(int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;
        while(!st.empty() && st.top() <= nums[idx]) {
            st.pop();
        }
        if(i < n) {
            if(!st.empty()) res[idx] = st.top();
        }
        st.push(nums[idx]);
    }

    return res;
}