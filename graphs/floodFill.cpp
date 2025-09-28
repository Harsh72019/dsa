#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int toChange = image[sr][sc];
        if (toChange == color) return image;
        image[sr][sc] = color;
        queue<pair<int,  int>> q;
        q.push({sr , sc});
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while(!q.empty())
        {
            auto coordinates = q.front();
            q.pop();
            int x = coordinates.first;
            int y = coordinates.second;
            for(int d = 0 ; d < 4 ; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < image.size() && ny >=0 && ny < image[0].size() && image[nx][ny] == toChange)
                {
                    image[nx][ny] = color;
                    q.push({nx , ny});
                }
            }

        }   
        return image; 
    }