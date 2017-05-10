//coding:utf-8
/***********************************************************
Program: 557
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-04-14 18:59:53
Last modified: 2017-04-14 19:00:00
GCC version: 4.9.3
***********************************************************/

public:
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {   // when i is a non-space
                int j = i;
                for (; j < s.length() && s[j] != ' '; j++) { } // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        
        return s;
    }
};
