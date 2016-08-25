//coding:utf-8
/**********************************************
Program: 375 Guess number higher or lower II
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-25 13:49:19
Last modified: 2016-08-25 14:11:17
**********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
    int getMoneyAmount(vector<vector<int>>& t, int s, int e) {
        if(s >= e)
            return 0;
        if(t[s][e] != 0)
            return t[s][e];
        int ret = INT_MAX;
        for(int x = s; x <= e; ++x) {
            int tmp = x + max(getMoneyAmount(t, s, x - 1), getMoneyAmount(t, x + 1, e));
            ret = min(ret, tmp);
        }
        t[s][e] = ret;
        return ret;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));
        return getMoneyAmount(t, 1, n);
    }
};

int main() {
    return 0;
}

