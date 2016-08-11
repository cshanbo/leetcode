//coding:utf-8
/***********************************************************
Program: Convert Sorted Array to Balanced BST
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 13:23:36
Last modified: 2016-08-11 16:16:04
GCC version: 4.9.3
***********************************************************/

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ret = new TreeNode(0);
        ret = helper(nums, 0, nums.size() - 1);
        return ret;
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
