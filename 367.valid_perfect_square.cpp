//coding:utf-8
/*****************************************
Program: valid perfect square
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-18 08:35:05
Last modified: 2016-08-18 08:35:26
GCC version: 4.9.3
*****************************************/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long int l = 1, r = num, m = (l + r) / 2;
        while(l <= r) {
            if(m * m == num)
                return true;
            if(m * m < num) {
                l = m + 1;
                m = (l + r) / 2;
            }
            else {
                r = m - 1;
                m = (l + r) / 2;
            }
        }
        return false;
    }
};
