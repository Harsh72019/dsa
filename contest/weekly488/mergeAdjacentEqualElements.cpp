#include <bits/stdc++.h>
using namespace std;

vector<long long> mergeAdjacent(vector<int> &nums)
{
    stack<long long> st;
    for (int it : nums)
    {
        long long element = (long long)it;
        while (!st.empty() && element == st.top())
        {
            element += st.top();
            st.pop();
        }
        st.push(element);
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