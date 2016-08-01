//coding:utf-8
/***********************************************************
Program: Sudoku Solver
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-01 19:49:33
Last modified: 2016-08-01 20:23:16
GCC version: 4.9.3
***********************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
        for(int row = 0; row < 9; row++)
            if(board[row][j] == c)
                return false;
        for(int col = 0; col < 9; col++)
            if(board[i][col] == c)
                return false;
        int k = i / 3 * 3, l = j / 3 * 3;
        for(int row = k; row < k + 3; row++)
            for(int col = l; col < l + 3; col++)
                if(board[row][col] == c)
                    return false;
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backTrack(board, 0, 0);
    }
    bool backTrack(vector<vector<char>>& board, int i, int j) {
        if(j == 9) {
            j = j % 9;
            i++;
        }
        if(i == 9)
            return true;
        if(board[i][j] == '.') {
            for(char c = '1'; c <= '9'; c++) {
                if(isValid(board, i, j, c)) {
                    board[i][j] = c;
                    if(backTrack(board, i, j+1))
                        return true;
                    board[i][j] = '.';
                }
            }
            return false;
        } else
            return backTrack(board, i, j+1);
    }
};
