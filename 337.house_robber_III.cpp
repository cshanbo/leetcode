//coding:utf-8
/*****************************************
Program: house robber III
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-29 15:18:42
Last modified: 2016-08-29 15:23:36
GCC version: 4.9.3
*****************************************/
//
// typical dfs solution
// where, the max value is root + root.grandchildren or rob(root.left) + rob(root.right)
#include <algorithm>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = rob(root->left, ll, lr);
        r = rob(root->right, rl, rr);
        
        return std::max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode* root) {
        int l, r;
        return rob(root, l, r);
    }
};
