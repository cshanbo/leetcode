//coding:utf-8
/***********************************************************
Program: 
Description: Typical DFS solution
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-03-26 14:29:19
Last modified: 2017-03-26 14:29:43
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    int maxdiadepth = 0;
    
    int dfs(TreeNode* root){        
        if(root == NULL) return 0;
        
        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);
        
        if(leftdepth + rightdepth > maxdiadepth) maxdiadepth = leftdepth + rightdepth;
        return max(leftdepth +1, rightdepth + 1);     
    }
    
    int diameterOfBinaryTree(TreeNode* root) {        
        dfs(root);
        
        return maxdiadepth;
    }
};
