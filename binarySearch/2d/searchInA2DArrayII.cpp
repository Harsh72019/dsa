#include<bits/stdc++.h>
using namespace std;

// This was my approach of solving search matrix by going diagonally
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i = 0 ; i < matrix.size() && i < matrix[0].size(); i++)
    {
        int low = i;
        int high = matrix[0].size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) /2;
            if(matrix[i][mid] == target)
                return true;
            else if(matrix[i][mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        low = i;
        high = matrix.size() -1 ;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(matrix[mid][i] == target)
                return true;
            else if(matrix[mid][i] > target)
                high = mid - 1;
            else 
                low = mid + 1;

        }
    }
    return false;
}

// This is the optimized version
bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int row = 0;
    int col = cols - 1;
    
    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--;  // move left
        } else {
            row++;  // move down
        }
    }
    
    return false;
}