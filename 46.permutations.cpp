//coding:utf-8
/******************************************
Program: Permutations
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-02 09:30:16
Last modified: 2016-08-17 16:21:40
GCC version: 4.7.3
std = C++ 11
******************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    void helper(vector<vector<int>>& ret, vector<int>& nums, vector<int>& one, int idx) {
        if(idx >= nums.size()) {
            ret.push_back(one);
            return;
        }

        for(int i = idx; i < nums.size(); ++i) {
            swap(nums[idx], nums[i]);
            one = nums;
            helper(ret, nums, one, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> one;
        vector<vector<int>> ret;
        helper(ret, nums, one, 0);
        return ret;
    }
};

