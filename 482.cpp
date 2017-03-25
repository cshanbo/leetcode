//coding:utf-8
/***********************************************************
Program: License key formatting
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-03-25 16:06:37
Last modified: 2017-03-25 16:06:55
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        for (auto i = S.rbegin(); i < S.rend(); i++)
            if (*i != '-') { // ignore '-' in original string
                if (res.size() % (K+1) == K) 
                    res += '-'; // every (K+1)th char is '-' from tail
                res += toupper(*i);
            }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
