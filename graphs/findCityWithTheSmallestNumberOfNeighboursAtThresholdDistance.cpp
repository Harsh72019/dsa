#include<bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n , INT_MAX));
        for(int i = 0; i < edges.size() ; i++)
        {
            distance[edges[i][0]][edges[i][1]] = edges[i][2];
            distance[edges[i][1]][edges[i][0]] = edges[i][2];
            // distance[i][i] = 0;
        }
        for(int i = 0 ; i < n ; i ++)
        {
            distance[i][i] = 0;
        }

        for(int via = 0 ; via < n ; via ++)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ;j++)
                {
                    if(distance[i][via] != INT_MAX && distance[via][j] != INT_MAX)
                        distance[i][j] = min(distance[i][j] , distance[i][via] + distance[via][j]);
                }
            }
        }        
        int ans = 0;
        int currentCounter = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {   
            int counter = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(i!= j && distance[i][j] <= distanceThreshold)
                    counter++;
            }
            if(counter <= currentCounter)
            {
                ans = i;
                currentCounter = counter;
            }
        }
        return ans;

    }