//coding:utf-8
/***********************************************************
Program: 
Description: Check the sum so far
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-15 23:27:47
Last modified: 2017-05-15 23:28:23
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0, max_len = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for(int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] == 0?-1: 1);
            if(map.find(cnt) == map.end())
                map[cnt] = i;
            else 
                max_len = max(max_len, i - map[cnt]);
        }
        return max_len;
    }
};

