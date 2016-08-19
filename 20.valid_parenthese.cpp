//coding:utf-8
/******************************************
Program: Valid parentheses
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-25 13:13:16
Last modified: 2016-08-19 08:35:13
GCC version: 4.7.3
std = C++ 11
******************************************/

#include <string>

class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0)
            return false;
        stack<char> stk;
        for(auto c: s) {
            if(c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if((c == ')' && !stk.empty() && stk.top() == '(') || ((c == ']' && !stk.empty() && stk.top() == '[')) || ((c == '}' && !stk.empty() && stk.top() == '{')))
                    stk.pop();
            else
                return false;
        }
        return stk.empty();
    }
};
