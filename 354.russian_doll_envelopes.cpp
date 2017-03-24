//coding:utf-8
/*****************************************
Program: 354. Russian Doll Envelopes
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-19 09:30:43
Last modified: 2016-08-23 08:10:21
GCC version: 4.9.3
*****************************************/

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
    bool static compare(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first < p2.first || (p1.first >= p2.first && p1.second < p2.second);
    }
    
    bool valid(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first < p2.first && p1.second < p2.second;
    }
public:
    //int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    //    if(envelopes.empty())
    //        return 0;
    //    sort(envelopes.begin(), envelopes.end(), compare);
    //    int ret = 1, maxres = 1;
    //    for(int i = 0; i < envelopes.size() - 1; ++i) {
    //        if(valid(envelopes[i], envelopes[i + 1]))
    //            ret++;
    //        else {
    //            maxres = max(maxres, ret);
    //            ret = 1;
    //        }
    //    }
    //    return maxres + 1;
    //}
};

int main() {
    Solution s;
}



