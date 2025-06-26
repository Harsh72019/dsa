#include<bits/stdc++.h>
using namespace std;


 int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
    efforts[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    
    pq.push({0, {0, 0}});

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!pq.empty()) {
        int effort = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        if (x == rows - 1 && y == cols - 1)
            return effort;

        for (int d = 0; d < 4; ++d) {
            int newX = x + dx[d];
            int newY = y + dy[d];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                int heightDiff = abs(heights[x][y] - heights[newX][newY]);
                int maxEffort = max(effort, heightDiff); 

                if (maxEffort < efforts[newX][newY]) {
                    efforts[newX][newY] = maxEffort;
                    pq.push({maxEffort, {newX, newY}});
                }
            }
        }
    }

    return 0;
}