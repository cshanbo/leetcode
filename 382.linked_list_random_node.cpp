//coding:utf-8
/***********************************************************
Program:  382
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-10 10:30:57
Last modified: 2016-08-12 22:01:04
GCC version: 4.9.3
***********************************************************/
// the idea is Reservoir sampling
// https://en.wikipedia.org/wiki/Reservoir_sampling
#include "misc.h"
#include <random>

class Solution {
    ListNode* flag;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        flag = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = flag;
        int ret = node->val;
        for(int i = 1; node; ++i) {
            if(rand() % i == 0)
                ret = node->val;
            node = node->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

