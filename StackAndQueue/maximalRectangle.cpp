#include<bits/stdc++.h>
using namespace std;


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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dummy(rows, vector<int>(cols, 0));

        for (int j = 0; j < cols; j++) {
            dummy[0][j] = (matrix[0][j] == '1') ? 1 : 0;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dummy[i][j] = (matrix[i][j] == '1') ? dummy[i - 1][j] + 1 : 0;
            }
        }

        int ans = 0;
        for (int i = 0; i < rows; i++) {
            ans = max(ans, largestRectangleArea(dummy[i]));
        }

        return ans;
    }