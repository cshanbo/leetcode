//coding:utf-8
/*****************************************
Program: longest increasing subsequence
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-19 14:46:59
Last modified: 2016-08-19 15:07:47
GCC version: 4.9.3
*****************************************/

#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> dp(nums.size(), 0);
        int size = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int idx = 0, j = size;
            while(idx != j) {
                int m = (idx + j) >> 1;
                if(dp[m] < nums[i])
                    idx = m + 1;
                else
                    j = m;
            }
            dp[idx] = nums[i];
            if(idx == size)
                size++;
        }
        return size;
    }
};
