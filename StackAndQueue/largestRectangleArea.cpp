#include<bits/stdc++.h>
using namespace std;

// My brute force approach
// Time complexity: O(n^2)
  int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int left = i;
            int right = i;

            while (left >= 0 && heights[left] >= height) left--;

            while (right < n && heights[right] >= height) right++;

            int width = right - left - 1;
            ans = max(ans, width * height);
        }

        return ans;
    }

// Optimized approach using stack
// Time complexity: O(n)
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;  
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                int index = st.top().first;
                int height = st.top().second;
                st.pop();
                int width = i - index;
                maxArea = max(maxArea, height * width);
                start = index;  
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();
            int width = n - index;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }