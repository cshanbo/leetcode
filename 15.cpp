//coding:utf-8
/*
Program: 3sum
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-19 08:26:15
Last modified: 2016-07-19 08:26:26
GCC version: 4.7.3
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            int target = -1 * nums[i], l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[l] + nums[r] > target)
                    r--;
                else if(nums[l] + nums[r] < target)
                    l++;
                else {
                    vector<int> vec{nums[i], nums[l], nums[r]};
                    ret.push_back(vec);
                    while(l < r && nums[l] == vec[1])
                        l++;
                    while(l < r && nums[r] == vec[2])
                        r--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return ret;
    }
};
