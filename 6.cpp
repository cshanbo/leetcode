//coding:utf-8
/*
Program: zigzag
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-19 08:25:26
Last modified: 2016-08-17 14:33:24
GCC version: 4.7.3
*/

#include <string>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ret = "";
        for(int i = 0; i < numRows; ++i) {
            int first = (numRows - i - 1) * 2, second = i * 2;
            int index = i, flag = 0;
            while(index < s.length()) {
                ret += s[index];
                if(first == 0 || second == 0)
                    index += (numRows - 1) * 2;
                else if(flag % 2 == 0){
                    flag++;
                    index += first;
                } else {
                    flag++;
                    index += second;
                }
            }
        }
        return ret;
    }
};
