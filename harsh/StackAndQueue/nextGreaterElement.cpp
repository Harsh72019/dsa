#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int , int> um;
    
    for(int i = nums2.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums2[i])
            st.pop();
        if(st.empty())
            um[nums2[i]] = -1;
        else 
            um[nums2[i]] = st.top();
        st.push(nums2[i]);
    }

    for(int i = 0; i < nums1.size(); i++) {
        nums1[i] = um[nums1[i]];
    }

    return nums1;
}