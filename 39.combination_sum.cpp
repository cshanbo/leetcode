//coding:utf-8
/***********************************************************
Program: Combination Sum
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-29 15:33:14
Last modified: 2016-08-11 12:27:13
GCC version: 4.9.3
***********************************************************/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//standard backtracking solution
class Solution {
    void helper(vector<int>& candidates, vector<vector<int>>& ret, vector<int>& one, int num, int index) {
        if(num == 0 || index == candidates.size()) {
            ret.push_back(one);
            return;
        }
        for(int i = index; i < candidates.size() && num >= candidates[i]; ++i) {
            one.push_back(candidates[i]);
            helper(candidates, ret, one, num - candidates[i], i);
            one.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return ret;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        int num = 0;
        vector<int> one;
        helper(candidates, ret, one, target, 0);
    }
};
