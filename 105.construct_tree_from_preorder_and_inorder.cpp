//coding:utf-8
/***********************************************************
Program: construct tree from preorder and inorder
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 15:00:40
Last modified: 2016-08-11 15:10:14
GCC version: 4.9.3
***********************************************************/

//The first node of preorder is root, find this node in inorder vector, split the vector into two halves and continue this recursion
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }

    TreeNode* helper(vector<int>& inorder, int i, int j, vector<int>& preorder, int ii, int jj) {

        if(i >= j || ii >= jj)
            return NULL;

        //mid of inorder is the first of preorder
        int mid = preorder[ii];

        auto f = find(inorder.begin() + i, inorder.begin() + j, mid);
        
        //dist from the beginning of the inorder slice
        int dis = f - inorder.begin() - i;

        TreeNode* root = new TreeNode(mid);
        
        root -> left = helper(inorder, i, i + dis, preorder, ii + 1, ii + 1 + dis);
        root -> right = helper(inorder,i + dis + 1, j, preorder ,ii + 1 + dis, jj);

        return root;

    }
};
