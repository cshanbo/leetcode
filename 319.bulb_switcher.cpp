//coding:utf-8
/*****************************************
Program: Bubble switcher
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-18 14:20:24
Last modified: 2016-08-18 14:33:55
GCC version: 4.9.3
*****************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 1)
            return n;
        vector<int> v(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            int x = 1;
            while(i * x < v.size())
                v[i * x++]++;
        }
        int ret = 0;
        for(int i = 1; i < v.size(); ++i)
            if(v[i] % 2 == 1)
                ret++;
        return ret;
    }
};

int main() {
    Solution s;
    s.bulbSwitch(4);
}
