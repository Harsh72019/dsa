#include<bits/stdc++.h>
using namespace std;


void shortestDistance(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for(int via = 0 ; via < n ; via++)
    {
        for(int row = 0 ; row < n ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                matrix[row][col] = min(matrix[row][col] , matrix[row][via] + matrix[via][col]);
            }
        }
    }
}