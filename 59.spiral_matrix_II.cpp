//coding:utf-8
/*****************************************
Program: spiral matrix II
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-29 16:08:51
Last modified: 2016-08-29 16:23:35
GCC version: 4.9.3
*****************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<pair<int, int>> dir{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int idx = 0;
        int i = 0, j = 0, val = 1, sq = n * n;
        while(val <= sq) {
            if(i >= 0 && i < n && j >= 0 && j < n && ret[i][j] == 0) {
                ret[i][j] = val++;
                i += dir[idx % 4].first;
                j += dir[idx % 4].second;
            }

            if(!(i >= 0 && i < n && j >= 0 && j < n && ret[i][j] == 0)) {
                i -= dir[idx % 4].first;
                j -= dir[idx % 4].second;
                idx++; 
                i += dir[idx % 4].first;
                j += dir[idx % 4].second;
            }
        }
        return ret;
    }
};

void print(vector<vector<int>> maxtrix) {
    for(auto vec: maxtrix) {
        for(auto d: vec)
            cout << d << " ";
        cout << endl;
    }
}

int main() {
    Solution s;
    print(s.generateMatrix(5));
}
