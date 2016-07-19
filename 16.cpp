//coding:utf-8
/*
Program: 16
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-19 20:06:37
Last modified: 2016-07-19 20:07:21
GCC version: 4.9.3
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dist = INT_MAX, ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            int leftVal = nums[l], rightVal = nums[r], mid = nums[i];
            while(l < r) {
                int d = nums[i] + nums[l] + nums[r] - target;
                dist = dist >= abs(d)? abs(d): dist;
                ret = dist >= abs(d)? (nums[i] + nums[l] + nums[r]): ret;
                leftVal = nums[l];
                rightVal = nums[r];
                if(d > 0)
                    r--;
                else if(d == 0)
                    return target;
                else
                    l++;
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return ret;
    }
};

