#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>& board, string word, int i, int j, int index) {
    if(index == word.size())
        return true;

    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#'; 

    bool found = check(board, word, i + 1, j, index + 1) ||
                 check(board, word, i - 1, j, index + 1) ||
                 check(board, word, i, j + 1, index + 1) ||
                 check(board, word, i, j - 1, index + 1);

    board[i][j] = temp;  
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == word[0]) {
                if(check(board, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}