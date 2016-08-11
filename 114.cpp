//coding:utf-8
/***********************************************************
Program: Flatten Binary Tree to Linked List
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 16:25:36
Last modified: 2016-08-11 16:40:30
GCC version: 4.9.3
***********************************************************/
#include "misc.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        if(root->left) {
            root->right = root->left;
            root->left = NULL;
            while(root->right)
                root = root->right;
            root->right = temp;
        }
        
    }
};

int main() {}
