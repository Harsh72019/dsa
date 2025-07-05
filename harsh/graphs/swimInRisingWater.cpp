#include<bits/stdc++.h>
using namespace std;


    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n , vector<bool>(n  , false));

        priority_queue<vector<int> , vector<vector<int>> , greater<>> pq;
        pq.push({grid[0][0] , 0 , 0});
        visited[0][0] = true;

        vector<int> dx = {0 , 0 , -1 , 1};
        vector<int> dy = {-1 , 1 , 0 , 0};

        while(!pq.empty())
        {
            auto curr = pq.top(); pq.pop();
            int currentTime = curr[0];
            int currX = curr[1];
            int currY = curr[2];

            if(currX == n-1 && currY == n-1)
                return currentTime;

            for(int d = 0 ; d < 4 ; d++)
            {
                int newX = currX + dx[d];
                int newY = currY + dy[d];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY])
                {
                    visited[newX][newY] = true; 
                    int newTime = max(currentTime, grid[newX][newY]);  
                    pq.push({newTime , newX  , newY});
                }
            }
        }

        return -1;
    }