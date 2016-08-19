//coding:utf-8
/******************************************
Program: strstr
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-25 14:11:22
Last modified: 2016-07-25 14:34:42
GCC version: 4.7.3
std = C++ 11
******************************************/
//KMP algorithm

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int len = needle.length();
        int next[len];
        getNext(needle, next);
        int i = 0;
        int j = 0;
        while (i < haystack.length() && j < len){
            if (j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }
            else
                j = next[j];
        }
        if (j == len)
            return i - j;
        else
            return -1;
    }

    void getNext(string p, int next[]){
        int pLen = p.length();
        next[0] = -1;
        int k = -1;
        int j = 0;
        while (j < pLen - 1){
            if (k == -1 || p[j] == p[k]){
                ++k;
                ++j;
                next[j] = k;
            }
            else
                k = next[k];
        }
    }
};
