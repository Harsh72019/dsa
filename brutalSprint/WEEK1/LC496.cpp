#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<pair<int, int>> st;
    int m = nums2.size();
    unordered_map<int, int> um;
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!st.empty() && st.top().first < nums2[i])
        {
            auto it = st.top();
            um[it.first] = nums2[i];
            st.pop();
        }
        st.push({nums2[i], i});
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        if (um.find(nums1[i]) != um.end())
        {
            nums1[i] = um[nums1[i]];
        }
        else
            nums1[i] = -1;
    }
    return nums1;
}