#include<bits/stdc++.h>
using namespace std;


 void dfs(vector<vector<char>>& board , vector<vector<bool>>& visited , int row , int col)
    {
        if(row < 0 || row >=board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] == 'X')
            return;
        visited[row][col] = true;
        dfs(board , visited , row + 1, col);        
        dfs(board , visited , row - 1, col);        
        dfs(board , visited , row , col + 1);        
        dfs(board , visited , row , col - 1);        
    }

    
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows , vector<bool>(cols , false));
        for(int i = 0 ; i < rows ; i++)
        {
            if(board[i][0] == 'O')
                dfs(board , visited , i , 0);
            if(board[i][cols-1] == 'O')
                dfs(board , visited , i , cols-1);
        }
        for(int i = 0 ; i < cols ; i++)
        {
            if(board[0][i] == 'O')
                dfs(board, visited , 0 , i);
            if(board[rows-1][i] == 'O')
                dfs(board , visited , rows- 1 , i);
        }
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                if(!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }