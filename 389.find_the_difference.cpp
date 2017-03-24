//coding:utf-8
/**********************************************
Program: Find the differnce
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-29 09:12:05
Last modified: 2016-08-29 09:16:50
**********************************************/

#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for (auto x: s)
            c ^= x;
        for (auto x: t)
            c ^= x;
        return c;
    }
};
