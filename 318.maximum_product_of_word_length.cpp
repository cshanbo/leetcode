//coding:utf-8
/*****************************************
Program: maximum product of word lengths
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-29 16:31:13
Last modified: 2016-08-29 16:49:38
GCC version: 4.9.3
*****************************************/

// The idea is using a value vector to store a bit representation, which represents the characters of each word in origin vector
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> value(words.size(), 0);
        for(int i = 0; i < words.size(); ++i)
            for(auto c: words[i])
                value[i] |= 1 << (c - 'a');

        int ret = 0;
        for(int i = 1; i < words.size(); ++i)
            for(int j = 0; j < i; ++j)
                if((value[i] & value[j]) == 0 && words[i].length() * words[j].length() > ret)
                    ret = words[i].length() * words[j].length();
        return ret;
    }
};
