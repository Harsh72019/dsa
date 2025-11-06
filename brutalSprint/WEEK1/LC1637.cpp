#include <bits/stdc++.h>
using namespace std;

vector<int> mostCompetitive(vector<int> &nums, int k)
{
    stack<int> st;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > nums[i] && (st.size() - 1 + (n - i)) >= k)
            st.pop();

        if (st.size() < k)
            st.push(nums[i]);
    }

    vector<int> ans(k);
    for (int i = k - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}