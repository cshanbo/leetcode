//coding:utf-8
/***********************************************************
Program: Matchstick to square
Description: Standard DFS solution, still have the improving space
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-15 23:48:02
Last modified: 2017-05-15 23:49:17
GCC version: 4.9.3
***********************************************************/

class Solution {
    bool helper(vector<int>& nums, vector<int>& sides, int i, int side) {
        if(i == nums.size())
            return sides[0] == side && sides[1] == side && sides[2] == side;
        
        for(int idx = 0; idx < 4; ++idx) {
            if(nums[i] + sides[idx] > side) 
                continue;
            sides[idx] += nums[i];
            if(helper(nums, sides, i+1, side))
                return true;
            sides[idx] -= nums[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int len = 0;
        for(auto x: nums)
            len += x;
        if(len % 4 != 0)
            return false;
        int side = len / 4;
        vector<int> sides(4, 0);
        return helper(nums, sides, 0, side);
    }
};
