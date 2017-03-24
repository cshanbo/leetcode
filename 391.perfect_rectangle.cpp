//coding:utf-8
/**********************************************
Program: Perfect Rectangle
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-29 09:32:37
Last modified: 2016-08-29 10:11:33
**********************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print(vector<vector<int>> vec) {
    for(auto v: vec) {
        for(auto i: v)
            cout << i << " ";
        cout << endl;
    }
}

class Solution {
    bool static compare(vector<int> v1, vector<int> v2) {
        return v1[0] <= v2[0] && v1[1] <= v2[1];
    }

    int calc_area(vector<int>& vec) {
        return (vec[2] - vec[0]) * (vec[3] - vec[1]);
    }
    
    bool overlap(vector<int> v1, vector<int> v2) {
        return v2[1] < v1[3] && v2[0] < v1[3];
    }

public:

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), compare);
        print(rectangles);
        int area = calc_area(rectangles[0]);
        for(int i = 1; i < rectangles.size(); ++i) {
            if(overlap(rectangles[i - 1], rectangles[i]))
                return false;
            area += calc_area(rectangles[i]);
        }
        vector<int> bigone{rectangles[0][0], rectangles[0][1], rectangles[rectangles.size() - 1][2], rectangles[rectangles.size() - 1][3]};
        return area == calc_area(bigone);
    }

};

int main() {
    vector<vector<int>> vec{{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    Solution s;
    s.isRectangleCover(vec);
}
