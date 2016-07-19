//coding:utf-8
/*
Program: 374
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-13 16:28:35
Last modified: 2016-07-13 16:52:50
GCC version: 4.9.3
*/
#include <iostream>
using namespace std;
int guess(int num, int a) {
    if (num == a)
        return 0;
    if (num < a)
        return -1;
    if (num > a)
        return 1;
}

class Solution {
    public:
    int guessNumber(int n) {
        int x = (1 + n) >> 1,  l = 1,  h = n;
        int g = guess(x, 6);
        while(g != 0) {
            if(g == -1) {
                l = x + 1;
                x = (l + h) >> 1;
                g = guess(x, 7);
            } else {
                h = x - 1;
                x = (l + h) >> 1;
                g = guess(x, 7);
            }
        }
        return x;
    }
};

int main() {
    Solution slt;
    cout << slt.guessNumber(10) << endl;
}
