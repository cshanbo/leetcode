//coding:utf-8
/***********************************************************
Program: 
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-10 14:03:25
Last modified: 2016-08-17 10:50:49
GCC version: 4.9.3
***********************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//inorder traverse, the first element is the one bigger than the successor 
//second element is the one smaller the previous ones
//
#include "misc.h"

class Solution {
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        traverse(root);
        swap(first->val, second->val);
    }
    
    void traverse(TreeNode* root) {
        if(!root)
            return;
        traverse(root->left);
        if (!first && prev->val >= root->val)
            first = prev;
    
        if (first && prev->val >= root->val)
            second = root;
            
        prev = root;
        traverse(root->right);
    }
};
