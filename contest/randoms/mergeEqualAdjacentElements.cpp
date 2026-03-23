#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int> &nums)
    {
        stack<long long> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            long long ele = nums[i];
            while (!st.empty() && st.top() == ele)
            {
                ele += st.top();
                st.pop();
            }
            st.push(ele);
        }
        vector<long long> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};