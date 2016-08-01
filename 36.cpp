//coding:utf-8
/***********************************************************
Program: Valid Sudoku
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-01 17:55:53
Last modified: 2016-08-01 18:28:37
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int idx = board[i][j] - idx, k = i / 3 * 3 + j / 3;
                    if(row[i][idx] || col[idx][j] || box[k][idx])
                        return false;
                    row[i][idx] = col[idx][j] = box[k][idx] = 1;
                }
            }
        return true;
    }
};
