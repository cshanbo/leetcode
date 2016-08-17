//coding:utf-8
/*****************************************
Program: Mini Parser
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-17 14:21:22
Last modified: 2016-08-17 14:27:22
GCC version: 4.9.3
*****************************************/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <stack>

class Solution {
    stack<NestedInteger> nstk;
public:
    NestedInteger deserialize(string s) {
        int num = 0;
        int idx = 0;
        if(s[0] != '[')
            return NestedInteger(stoi(s));
        
        int sign = 1;
        for(int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if(c == '[') {
                nstk.push(NestedInteger());
                continue;
            } else if(c == ']' && nstk.size() > 1) {
                auto temp = nstk.top();
                nstk.pop();
                nstk.top().add(temp);
            } else if(c == ',') {
                continue;
            } else if(c == '-')
                sign = -1;
            else if(c >= '0' && c <= '9'){
                num = c - '0';
                while(i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9' )
                    num = num * 10 + (s[(i++) + 1] - '0');
                num *= sign;
                if(!nstk.empty())
                    nstk.top().add(NestedInteger(num));
                else
                    nstk.push(NestedInteger(num));
                sign = 1;
            }
        }
        
        return nstk.empty()? NestedInteger(): nstk.top();
    }
};
