//coding:utf-8
/*****************************************
Program: 383 ransom note
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-11 12:13:40
Last modified: 2016-08-11 12:23:04
GCC version: 4.9.3
*****************************************/

#include <unordered_map>
class Solution {
    unordered_map<char, int> count;
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.empty())
            return true;
        if(magazine.empty())
            return false;
        for(auto c: magazine)
            count[c]++;
        for(auto c: ransomNote) {
            if(count.find(c) == count.end() || count[c] == 0)
                return false;
            count[c]--;
        }
        return true;
    }
};
