//coding:utf-8=
/*
Program: 373
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-08 15:57:16
Last modified: 2016-07-11 16:22:37
GCC version: 4.9.3
*/

//most trival method, sort
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
static bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

class Solution {
public:
    vector<pair<int,  int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int index1 = 0, index2 = 0;
        vector<pair<int, int>> ret;
        for(auto a: nums1)
            for(auto b: nums2) {
                auto p = make_pair(a, b);
                ret.push_back(p);
            }
        sort(ret.begin(), ret.end(), compare);
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

int main() {
    Solution slt;
    vector<int> nums1 = {1, 7, 10}, nums2 = {2, 4, 6};
    slt.print(slt.kSmallestPairs(nums1, nums2, 0));
    return 0;
}
