//coding:utf-8
/***********************************************************
Program: Convert Sorted Array to Balanced BST
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 13:23:36
Last modified: 2016-08-11 16:22:02
GCC version: 4.9.3
***********************************************************/

#include <iostream>
#include <vector>
#include "misc.h"
using namespace std;

// Basic Depth First Search Solution
// Each time, choose the middle one as the root
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int> &nums, int l, int r){
        if(l > r)
            return NULL;
        int m = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = helper(nums, l, m - 1);
        node->right = helper(nums, m + 1, r);
        return node;
    }
};

int main() {
    return 0;
}
