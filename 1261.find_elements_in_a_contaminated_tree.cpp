//coding:utf-8
/***********************************************************
Program: 1261
Description: I think this one should be categorized as `easy`.
Shanbo Cheng: cshanbo@gmail.com
Date: 2020-01-09 21:31:49
Last modified: 2020-01-09 21:32:26
GCC version: 4.9.3
***********************************************************/

class FindElements {
    unordered_set<int> vals;
public:
    void helper(TreeNode* root, int val) {
        if(!root)
            return;
        root->val = val;
        vals.insert(val);
        if(root->left)
            helper(root->left, 2 * root->val + 1);
        if(root->right)
            helper(root->right, 2 * root->val + 2);
    }
    FindElements(TreeNode* root) {
        helper(root, root->val + 1);
    }
    
    bool find(int target) {
        return vals.find(target) != vals.end();
    }
};
