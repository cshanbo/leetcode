//coding:utf-8
/*****************************************
Program: Rotate image
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-18 12:14:51
Last modified: 2016-08-18 12:31:43
GCC version: 4.9.3
*****************************************/
//Transpose first, then reverse each row

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = i; j < matrix[0].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        for(auto& vec: matrix)
            reverse(vec.begin(), vec.end());
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec {{1, 2}, {3, 4}};
    s.rotate(vec);
    for(auto v: vec) {
        for(auto d: v)
            cout << d << " ";
        cout << endl;
    }
}
