#include <bits/stdc++.h>
using namespace std;

vector<int> canSeePersonsCount(vector<int> &heights)
{
    stack<int> st;

    int n = heights.size();
    vector<int> ans(n, 0);
    for (int right = n - 1; right >= 0; right--)
    {
        int counter = 0;
        while (!st.empty() && st.top() <= heights[right])
        {
            st.pop();
            counter++;
        }
        if (!st.empty())
            counter++;
        st.push(heights[right]);
        ans[right] = counter;
    }
    return ans;
}