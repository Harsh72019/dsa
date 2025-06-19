#include<bits/stdc++.h>
using namespace std;


 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<pair<int,int> , int>> q;
        vector<vector<bool>> visited(rows , vector<bool>(cols , false));
        vector<vector<int>>  ans(rows , vector<int>(cols  , 0));

        for(int i = 0 ; i < rows ; i ++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({{i , j} , 0 });
                }
            }
        }


        vector<int> dx = {0 , 0 , 1 , -1};
        vector<int> dy = {1 , -1 , 0 , 0};


        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[row][col] = steps;
            for(int d = 0 ; d < 4 ; d++)
            {
                int nx = row + dx[d];
                int nc = col + dy[d];
                if(nx >= 0 && nx < rows && nc >= 0 && nc <cols && visited[nx][nc] == false)
                {
                    q.push({{nx , nc} , steps+ 1});
                    visited[nx][nc] = true;
                }
            }
        }
        return ans;

    }