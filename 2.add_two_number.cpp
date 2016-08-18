//coding:utf-8
/*
Program: add two number
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-06 18:42:55
Last modified: 2016-07-06 19:01:30
GCC version: 4.7.3
*/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = new ListNode(0);
        ListNode* ret = new ListNode(0);
        prev->next = ret;
        int last = 0, temp = 0;
        while(l1 && l2) {
            temp = l1->val + l2->val + last;
            last = temp / 10;
            temp = temp % 10;
            ListNode* node = new ListNode(temp);
            ret->next = node;
            ret = ret->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            temp = l1->val + last;
            last = temp / 10;
            temp = temp % 10;
            ListNode* node = new ListNode(temp);
            ret->next = node;
            ret = ret->next;
            l1 = l1->next;
        }

        while(l2) {
            temp = l2->val + last;
            last = temp / 10;
            temp = temp % 10;
            ListNode* node = new ListNode(temp);
            ret->next = node;
            ret = ret->next;
            l2 = l2->next;
        }

        if (last) {
            ListNode* node = new ListNode(last);
            ret->next = node;
        }
        return prev->next->next;
    }
};
