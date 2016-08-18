//coding:utf-8
/***********************************************************
Program: wiggle sequence
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-25 10:29:43
Last modified: 2016-07-25 11:06:08
GCC version: 4.9.3
***********************************************************/

#include <iostream>
#include <vector>
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int flag = 0, count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1] && (flag == -1 || flag == 0)) {
                ++count;
                flag = 1;
            } 
            else if (nums[i] < nums[i-1] && (flag == 1 || flag == 0)) {
                ++count;
                flag = -1;
            }
        }
        return nums.size() == 0 ? 0 : count;
    }
};

int main() {}
