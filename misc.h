//coding:utf-8
/***********************************************************
Program: misc header
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-11 16:17:04
Last modified: 2016-08-11 16:17:04
GCC version: 4.9.3
***********************************************************/

#include <vector>

template <typename T>
using matrix = std::vector<std::vector<T>>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
