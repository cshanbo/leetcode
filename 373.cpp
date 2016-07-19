//coding:utf-8
/*
Program: 373.cpp
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-08 22:24:54
Last modified: 2016-07-11 16:37:07
GCC version: 4.7.3
*/

#include <iostream>
#include <vector>
#include <algorithm>
static bool compare(pair<int,  int> a,  pair<int,  int> b) {
        return a.first + a.second < b.first + b.second;
}
class Solution {
public:
    vector<pair<int,   int>> kSmallestPairs(vector<int>& nums1,   vector<int>& nums2,   int k) {
        int index1 = 0,  index2 = 0;
        vector<pair<int,  int>> ret;
        for(auto a: nums1)
            for(auto b: nums2) {
                auto p = make_pair(a,  b);
                ret.push_back(p);
            }
            sort(ret.begin(),  ret.end(),  compare);
            if(k >= nums1.size() * nums2.size())
                return ret;
            else {
                auto v = ret;
                auto i = 0;
                v.clear();
                while(k--)
                    v.push_back(ret[i++]);
                return v;
            }
    }
};

