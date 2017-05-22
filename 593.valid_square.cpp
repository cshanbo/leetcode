//coding:utf-8
/***********************************************************
Program: Valid square
Description: Math
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-22 11:31:51
Last modified: 2017-05-22 13:44:34
GCC version: 4.9.3
***********************************************************/


#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

class Solution {
    float distance(vector<int>& p1, vector<int>& p2) {
        float x = pow(float(p1[0] - p2[0]), 2) + pow(float(p1[1] - p2[1]), 2);
        return x;
    }

public:
    bool setEqual(set<float>& set1, set<float> set2) {
        if(set1.size() != set2.size())
            return false;
        for(auto it = set1.begin(); it != set1.end(); ++it)
            if(set2.find(*it) == set2.end())
                return false;
        return true;
    }

    set<float> calculate(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<float> dists;
        dists.insert(distance(p1, p2));
        dists.insert(distance(p1, p3));
        dists.insert(distance(p1, p4));
        return dists;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1.size() != 2 || p2.size() != 2 || p3.size() != 2 || p4.size() != 2) {
            return false;
        }
        set<float> dist1 = calculate(p1, p2, p3, p4);
        if(dist1.size() != 2) {
            return false;
        }
        float min = *dist1.begin();
        float max = *dist1.rbegin();
        if(2 * min != max) {
            return false;
        }
        set<float> dist2 = calculate(p2, p1, p3, p4);
        set<float> dist3 = calculate(p3, p2, p1, p4);
        set<float> dist4 = calculate(p4, p2, p3, p1);
        return setEqual(dist1, dist2) && setEqual(dist1, dist3) && setEqual(dist1, dist4);
    }
};

int main() {
    Solution solution;
    vector<int> p1{0, 0};
    vector<int> p2{1, 1};
    vector<int> p3{1, 0};
    vector<int> p4{0, 1};
    cout << solution.validSquare(p1, p2, p3, p4) << endl;
    return 0;
}
