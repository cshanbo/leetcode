//coding:utf-8
/**********************************************
Program: Combination sum II
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-25 14:18:11
Last modified: 2016-08-25 14:34:19
**********************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> one;
        sort(candidates.begin(), candidates.end());
        backTrack(ret, candidates, one, target, 0);
        return ret;
    }

    void backTrack(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& one, int target, int index) {
        if(!target) {
            ret.push_back(one);
            return;
        }
        for(int i = index; i < candidates.size() && target >= candidates[i]; i++) {
            if(i > index && candidates[i] == candidates[i - 1]) 
                continue;
            one.push_back(candidates[i]);
            backTrack(ret, candidates, one, target - candidates[i], i + 1);
            one.pop_back();
        }
    }

};
