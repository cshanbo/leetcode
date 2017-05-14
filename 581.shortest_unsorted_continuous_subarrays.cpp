//coding:utf-8
/***********************************************************
Program: 581
Description: just need to track the index of begin and end, where begin > end 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-14 15:51:35
Last modified: 2017-05-14 15:52:47
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), b = -1, e = -2, mn = nums[n-1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (nums[i] < mx)
                e = i;
            if (nums[n - 1 - i] > mn)
                b = n - 1 - i;
        }
        return e - b + 1;
    }
};

