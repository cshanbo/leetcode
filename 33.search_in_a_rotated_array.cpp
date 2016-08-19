//coding:utf-8
/***********************************************************
Program: Search in a rotated array
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-29 14:13:10
Last modified: 2016-08-19 08:37:54
GCC version: 4.9.3
***********************************************************/

#include <vector>

class Solution {
    //firstly, binary search to find the rotation index, then binary search the two parts (could search only one too)
    int findMin(vector<int>& nums, int l, int r){
    	if(nums.size() == 1)
            return 0;
    	if (l < 0 || r < 0 || l >= nums.size() || r >= nums.size())
    		return -1;
    	int mid = l + (r - l) >> 1;
    	if (l <= r){
    		if (mid == 0)
    			return nums[mid] > nums[mid + 1] ? mid + 1 : -1;
    		if (mid == nums.size() - 1)
    			return nums[mid] < nums[mid - 1] ? mid : -1;
    		
    		if (nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1])
    			return mid;
    		else
    			return max(findMin(nums, l, mid - 1), findMin(nums, mid + 1, r));
    	}
    	
    	return -1;
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int& target){
        int m = (l + r)/2;
        while(l <= r){
            if(nums[m] == target)
                return m;
            else if(nums[m] > target){
                r = m - 1;
                m = l + (r - l) >> 1;
            }else{
                l = m + 1;
                m = l + (r - l) >> 1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int index = findMin(nums, 0, nums.size() - 1);
        if(index == -1)
            return binarySearch(nums, 0, nums.size() - 1, target);
        return max(binarySearch(nums, 0, index - 1, target), binarySearch(nums, index, nums.size() - 1, target));
    }
};
