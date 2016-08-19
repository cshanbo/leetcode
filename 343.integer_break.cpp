//coding:utf-8
/*****************************************
Program: Integer break
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-19 09:01:37
Last modified: 2016-08-19 09:15:54
GCC version: 4.9.3
*****************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n <= 2)
            return 1;
        vector<int> dp(n + 1, 0); 
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j < i; ++j)
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
        return dp[n];
    }
};
