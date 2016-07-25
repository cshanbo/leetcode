//coding:utf-8
/******************************************
Program: Generate parentheses
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-25 13:28:28
Last modified: 2016-07-25 13:28:42
GCC version: 4.7.3
std = C++ 11
******************************************/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string one = "";
        int left = 0, right = 0;
        dfs(ret, one, n, left, right);
        return ret;
    }
    
    void dfs(vector<string>& ret, string one, int n, int left, int right) {
        if(one.length() == 2 * n) {
            ret.push_back(one);
            return;
        }
        if(left == right && left < n)
            dfs(ret, one + "(", n, left + 1, right);
        else if(left > right && left < n) {
            dfs(ret, one + "(", n, left + 1, right);
            dfs(ret, one + ")", n, left, right + 1);
        } else if(left > right && left == n) 
            dfs(ret, one + ")", n, left, right + 1);
    }
};
