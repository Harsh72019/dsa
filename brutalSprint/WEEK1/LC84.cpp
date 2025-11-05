#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<pair<int, int>> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int start = i;

        while (!st.empty() && st.top().second > heights[i])
        {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();
            int width = i - index;
            maxArea = max(maxArea, height * width);
            start = index;
        }

        st.push({start, heights[i]});
    }

    while (!st.empty())
    {
        int index = st.top().first;
        int height = st.top().second;
        st.pop();
        int width = n - index;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}
