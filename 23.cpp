//coding:utf-8
/******************************************
Program: Merge k sorted lists
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-25 13:29:15
Last modified: 2016-07-25 13:30:00
GCC version: 4.7.3
std = C++ 11
******************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* head = new ListNode(0), *tail = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                tail->next = l2;
                l2 = l2->next;
            }
            else{
                tail->next = l1;
                l1 = l1->next;
            }
            tail = tail->next;
        }
        tail->next = l1 != NULL ? l1 : l2;
        return head->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        vector<ListNode*> temp = lists;
        while(lists.size() > 1) {
            lists = temp;
            temp.clear();
            int i = 0;
            for(; i < lists.size() - 1; i += 2) 
                temp.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            if(i == lists.size() - 1)
                temp.push_back(lists[lists.size() - 1]);
        }
        return lists[0];
    }
};
