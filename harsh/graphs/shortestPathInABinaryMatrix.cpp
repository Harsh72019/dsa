#include<bits/stdc++.h>
using namespace std;
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<vector<int>> distances(n , vector<int>(n , INT_MAX));
       distances[0][0] = 1;
       queue<pair<int , pair<int , int>>> q;
       q.push({1 , {0 , 0}});

       vector<int> dx = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
       vector<int> dy = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};
    
        while(!q.empty())
        {
            int distance = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if(x == n - 1 && y == n -1)
                return distance;
            
            for(int i = 0 ; i < 8 ; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX < 0 || newX >= n || newY < 0 || newY >= n || grid[newX][newY] == 1 || distance + 1 >= distances[newX][newY])
                    continue;
                
                distances[newX][newY] = distance + 1;
                q.push({distance + 1 , {newX , newY}});
            }
        }

        return -1;
    }