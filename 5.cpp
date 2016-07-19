//coding:utf-8
/*
Program: 5.cpp
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-13 19:54:49
Last modified: 2016-07-13 19:55:09
GCC version: 4.9.3
*/

class Solution {
    bool isPalindrome(string s, int l, int r) {
        while(l <= r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        int len = 1;
        string ret = s.substr(0, 1);
        for(int i = 1; i < s.length(); ++i) {
            if(isPalindrome(s, i - len - 1, i)) {
                len += 2;
                ret = s.substr(i - len + 1, len);
            } else if(isPalindrome(s, i - len, i)) {
                len++;
                ret = s.substr(i - len + 1, len);
            }
        }
        return ret;
    }
};
