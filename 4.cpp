//coding:utf-8
/*
Program: 4
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-07-11 13:13:12
Last modified: 2016-07-13 20:13:02
GCC version: 4.9.3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        vector<int> larger = sz1 >= sz2 ? nums1: nums2;
        vector<int> smaller = sz1 < sz2 ? nums2: nums1;
        int m = smaller.size(), n = larger.size();
        int imin = 0, imax = m, half = (m + n + 1) >> 1;
        while(imin <= imax) {
            int i = (imin + imax) >> 1;
            int j = half - i;
            if (j > 0 && i < smaller.size() && larger[j - 1] > smaller[i])
                imin = i + 1;
            else if(i > 0 && j < larger.size() && smaller[i - 1] > larger[j])
                imax = i - 1;
            else {
                int max_of_left, min_of_right;
                if(i == 0)
                    max_of_left = larger[j - 1];
                else if(j == 0)
                    max_of_left = smaller[i - 1];
                else
                    max_of_left = max(larger[j - 1], smaller[i - 1]);
                if((m + n) % 2 == 1)
                   return max_of_left; 
                if(i == m)
                    min_of_right = larger[j];
                else if(j == n)
                    min_of_right = smaller[i];
                else
                    min_of_right = min(larger[j], smaller[i]);
                return (max_of_left + min_of_right) >> 1;
            }
        }
    }
};
int main() {
    return 0;
}

