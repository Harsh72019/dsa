#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int currElement = temperatures[i];
        while (!st.empty() && st.top().first < currElement)
        {
            auto top = st.top();
            int index = top.second;
            ans[index] = i - index;
            st.pop();
        }
        st.push({currElement, i});
    }
    return ans;
}