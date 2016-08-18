//coding:utf-8
/*****************************************
Program: Longest increasing path in a matrix
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-18 16:02:43
Last modified: 2016-08-18 19:16:51
GCC version: 4.9.3
*****************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ret = 1;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                ret = max(ret, dfs(matrix, matrix[i][j] - 1, visited, i, j));
        return ret;
    }
    
    int dfs(vector<vector<int>>& matrix, int cur, vector<vector<int>>& visited, int i, int j) {
        if(visited[i][j] != 0)
            return visited[i][j];
        cur = matrix[i][j];
        int x, y, ret = 1;
        x = i + 1;
        y = j;
        if(!(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || cur >= matrix[x][y]))
            ret = max(ret, 1 + dfs(matrix, cur, visited, x, y));
        x = i - 1;
        y = j;
        if(!(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || cur >= matrix[x][y]))
            ret = max(ret, 1 + dfs(matrix, cur, visited, x, y));
        x = i;
        y = j + 1;
        if(!(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || cur >= matrix[x][y]))
            ret = max(ret, 1 + dfs(matrix, cur, visited, x, y));
        x = i;
        y = j - 1;
        if(!(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || cur >= matrix[x][y]))
            ret = max(ret, 1 + dfs(matrix, cur, visited, x, y));
        visited[i][j] = ret; 
        return visited[i][j];
    }
};

int main() {
    vector<vector<int>> mat{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    Solution s;
    cout << s.longestIncreasingPath(mat) << endl;
    return 0;
}
