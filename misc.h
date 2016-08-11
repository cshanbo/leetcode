//coding:utf-8
/***********************************************************
Program: misc header
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 16:17:04
Last modified: 2016-08-11 16:17:04
GCC version: 4.9.3
***********************************************************/

template <typename T>
using matrix = std::vector<std::vector<T>>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


