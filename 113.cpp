//coding:utf-8
/***********************************************************
Program: Path Sum II
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 16:14:09
Last modified: 2016-08-11 16:15:25
GCC version: 4.9.3
***********************************************************/

//A basic dfs solution, no other tricks
#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

template <typename T>
using matrix = vector<vector<T>>;
 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        matrix<int> ret;
        if(!root)
            return ret;
        vector<int> one;
        helper(root, ret, one, sum);
        return ret;
    }
    
    void helper(TreeNode* node, matrix<int>& ret, vector<int> one, int val) {
        if(!node)
            return;
        if(node && !node->left && !node->right && node->val == val) {
            one.push_back(val);
            ret.push_back(one);
            return;
        }

        one.push_back(node->val);
        helper(node->left, ret, one, val - node->val);
        helper(node->right, ret, one, val - node->val);
        return;
    }
};
