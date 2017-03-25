//coding:utf-8
/***********************************************************
Program: License key formatting
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-03-25 16:06:37
Last modified: 2017-03-25 16:40:34
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        for(int i = S.size() - 1; i >= 0; --i) {
            if(S[i] != '-') {
                if(res.length() % (K + 1) == K)
                    res = "-" + res;
                res = char(toupper(S[i])) + res;
            }
        }
        return res;
    }
};

