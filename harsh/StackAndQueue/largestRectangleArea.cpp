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
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }