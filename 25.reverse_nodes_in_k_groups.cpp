//coding:utf-8
/******************************************
Program: Reverse nodes in k group
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-25 13:33:19
Last modified: 2016-08-17 21:33:40
GCC version: 4.7.3
std = C++ 11
******************************************/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = new ListNode(0);
        ListNode* nxt = head->next;
        ListNode* hd = head;
        prev->next = head;
        while(nxt) {
            head->next = nxt->next;
            prev->next = nxt;
            nxt->next = hd;
            nxt = head->next;
            hd = prev->next;
        }
        return prev->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return new ListNode(0);
    }
};

void print(ListNode* node) {
    ListNode* n = node;
    while(n) {
        cout << n->val << " ";
        n = n->next;
    }
}

int main() {
    int i;
    ListNode* p = new ListNode(-1);
    ListNode* x = p;
    while(cin >> i && i != 999) {
        ListNode* one = new ListNode(i);
        x->next = one;
        x = x->next;
    }
    Solution slt;
    print(slt.reverse(p));
}
