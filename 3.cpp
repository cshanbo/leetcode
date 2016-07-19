//coding:utf-8
/*
Program: 
Description: 
Shanbo Cheng: cshanbo@gmail.com 
Date: 2016-07-06 15:00:26
Last modified: 2016-07-06 16:28:11
GCC version: 4.7.3
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    unordered_map<char, int> char_map;
public:
    int lengthOfLongestSubstring(string s) {
        char_map.clear();
        if(s.length() == 0)
            return 0;
        int ret = 0, index = 0, start = 0, res = 0;
        for(auto c: s) {
            if(char_map.find(c) == char_map.end()) {
                char_map[c] = index;
                res++;
                ret = max(ret, res);
            } else {
                start = max(start, char_map[c] + 1);
                char_map[c] = index;
                ret = max(ret, index - start + 1);
                res = index - start + 1;
            }
            index++;
        }
        return max(ret, res);
    }
};

int main() {
    Solution slt;
    string s;
    while(cin >> s) {
        cout << slt.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
