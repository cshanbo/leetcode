//coding:utf-8
/*****************************************
Program: Jump Game
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-17 15:19:33
Last modified: 2016-08-17 15:19:54
GCC version: 4.9.3
*****************************************/

#include <vector>

class Solution {
    bool helper(vector<int>& nums, int e){
        if(e == 0)
            return true;
        if(nums[e - 1] >= 1)
            return helper(nums, e - 1);
        else{
            if(e - 1 == 0)
                return false;
            for(int i = e - 2; i >= 0; i--){
                if(nums[i] >= e - i){
                    if(i >= 1)
                        return helper(nums, i);
                    else
                        return true;
                }
            }
            return false;
        }
    }
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, nums.size() - 1);
    }
};
