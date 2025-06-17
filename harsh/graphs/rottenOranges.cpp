#include<bits/stdc++.h>
using namespace std;

 int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int , int>> q;
        vector<vector<bool>> visited(row , vector<bool>(col , false));
        int freshCount = 0;

        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i , j});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1)
                {
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;
        int time = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while(!q.empty())
        {
            int size = q.size();
            time++;

            for(int i = 0 ; i < q.size() ; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int j = 0 ; j < 4 ; j++)
                {
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if(newX >= 0 && newX < row && newY >= 0 && newY < col && 
                       grid[newX][newY] == 1 && !visited[newX][newY])
                    {
                        visited[newX][newY] = true;
                        grid[newX][newY] = 2;
                        freshCount--;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return freshCount == 0 ? time - 1 : -1;
    }