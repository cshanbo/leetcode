//coding:utf-8
/*****************************************
Program: Longest increasing path in a matrix
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-18 16:02:43
Last modified: 2016-08-18 16:53:57
GCC version: 4.9.3
*****************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool max(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                ret = max(ret, dfs(matrix, matrix[i][j], ret, visited, i, j));
            }
        }
        
        return ret;
    }
    
    int dfs(vector<vector<int>>& matrix, int cur, int ret, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || visited[i][j] || cur >= matrix[i][j])
            return ret;
        int r = ret + 1;
        int temp = ret;
        visited[i][j] = true;
        return max(dfs(matrix, cur, r, visited, i + 1, j), 
                    dfs(matrix, cur, r, visited, i - 1, j), 
                    dfs(matrix, cur, r, visited, i, j + 1), 
                    dfs(matrix, cur, r, visited, i, j + 1));
    }
};

int main() {
    vector<vector<int>> mat{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    Solution s;
    cout << s.longestIncreasingPath(mat) << endl;
    return 0;
}
