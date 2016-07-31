//coding:utf-8
/***********************************************************
Program: Search for a range
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-29 14:19:23
Last modified: 2016-07-29 15:09:04
GCC version: 4.9.3
***********************************************************/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int binary(int l, int r, int target, vector<int>& nums) {
        int m = l + ((r - l) >> 1);
        while(l <= r) {
            if(nums[m] == target)
                return m;
            else if(nums[m] > target) {
                r = m - 1;
                m = l + ((r - l) >> 1);
            } else {
                l = m + 1;
                m = l + ((r - l) >> 1);
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m = binary(0, nums.size() - 1, target, nums);
        //didn't find
        if(m == -1)
            return vector<int> {-1, -1};
        //search left
        int l = 0, index = 0, r = m, mid = l + ((r - l) >> 1);
        if(nums[index] != target) {
            while(l <= r) {
                if(mid > 0 && nums[mid] == target && nums[mid - 1] != target) {
                    index = mid;
                    break;
                } else if (nums[mid] < target){
                    l = mid + 1;
                    mid = l + ((r - l) >> 1);
                } else if(mid > 0 && nums[mid] == target && nums[mid - 1] == target) {
                    r = mid - 1;
                    mid = l + ((r - l) >> 1);
                }
            }
        }
        int left = index;
        //search right
        l = m, index = nums.size() - 1, r = nums.size() - 1, mid = l + ((r - l) >> 1);
        if(nums[index] != target) {
            while(l <= r) {
                if(mid < nums.size() - 1 && nums[mid] == target && nums[mid + 1] != target) {
                    index = mid;
                    break;
                } else if(nums[mid] > target) {
                    r = mid - 1;
                    mid = l + ((r - l) >> 1);
                } else if(mid < nums.size() - 1 && nums[mid + 1] == target) {
                    l = mid + 1;
                    mid = l + ((r - l) >> 1);
                }
            }
        }
        int right = index; 
        return vector<int> {left, right};
    }
};

int main() {
    vector<int> vec{1, 2};
    int target = 3;
    Solution slt;
}
