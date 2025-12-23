#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // min-heap: {effort, row, col}
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>>
        pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    while (!pq.empty())
    {
        auto [effort, r, c] = pq.top();
        pq.pop();

        // Destination reached with minimum effort
        if (r == m - 1 && c == n - 1)
            return effort;

        if (effort > dist[r][c])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            int newEffort = max(
                effort,
                abs(heights[r][c] - heights[nr][nc]));

            if (newEffort < dist[nr][nc])
            {
                dist[nr][nc] = newEffort;
                pq.push({newEffort, nr, nc});
            }
        }
    }

    return 0; // guaranteed reachable
}
