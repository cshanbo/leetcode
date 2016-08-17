//coding:utf-8
/*****************************************
Program: Jump Game II
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-17 15:58:04
Last modified: 2016-08-17 16:15:04
GCC version: 4.9.3
*****************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int i = 0, temp = 0, level = 0, maxJump = 0;
        while(maxJump < nums.size()) {
            level++;
            for(; i <= temp; ++i) {
                maxJump = max(maxJump, nums[i] + i);
                if(maxJump >= nums.size() - 1)
                    return level;
            }
            temp = maxJump;
        }
        return level - 1;
    }
};

int main() {
    vector<int> vec{2, 3, 1, 1, 3, 1};
    Solution s;
    cout << s.jump(vec) << endl;
}
