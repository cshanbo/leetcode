//coding:utf-8
/*
Program: Sum root to leaf
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-18 15:46:42
Last modified: 2016-07-18 16:16:50
GCC version: 4.7.3
*/

#include <iostream>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
    void dfs(TreeNode* node, int& ret, int temp) {
        if(!node)
            return;
        if(!node->left && !node->right) {
            temp = temp * 10 + node->val; 
            ret += temp;
        }
        temp = 10 * temp + node->val;
        dfs(node->left, ret, temp);
        dfs(node->right, ret, temp);
        return;
    }
public:
    int sumTreeToleaf(TreeNode* root) {
        if(!root)
            return 0;
        int ret = 0;
        dfs(root, ret, 0);
        return ret;
    }
};

int main() {
    Solution slt;
    TreeNode* root = new TreeNode(1);
    TreeNode* l = new TreeNode(2);
    TreeNode* ll = new TreeNode(2);
    TreeNode* lr = new TreeNode(3);
    TreeNode* r = new TreeNode(3);
    l->left = ll;
    l->right = lr;
    root->left = l;
    root->right = r;
    cout << slt.sumTreeToleaf(root) << endl;
    return 0;
}

