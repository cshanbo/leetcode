//coding:utf-8
/***********************************************************
Program: 593
Description: Simple hashmap solution 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-22 14:19:35
Last modified: 2017-05-22 14:20:01
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto num : nums) {
            if(map.find(num) == map.end())
                map[num] = 1;
            else
                map[num] += 1;
        }
        int result = 0;
        for (auto iter = map.begin(); iter != map.end(); ++iter)
            if (map.find(iter->first + 1) != map.end())
                result = max(result, iter->second + map[iter->first + 1]);
        return result;
    }
};
