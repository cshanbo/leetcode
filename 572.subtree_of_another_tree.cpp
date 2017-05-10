//coding:utf-8
/***********************************************************
Program: Subtree of another tree
Description: Standard dfs solution
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-10 09:48:57
Last modified: 2017-05-10 09:51:51
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return !t || s && (same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
    }

private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        return !s ? !t : t && s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};
