//coding:utf-8
/*
Program: 
Description: 
Shanbo Cheng: cshanbo@gmail.com 
Date: 2016-07-06 15:00:26
Last modified: 2016-07-06 16:43:26
GCC version: 4.7.3
*/

//
//in this problem, leetcode #1, this code works, because it guarantees each test case has exactly one solution.
//otherwise, the code should be modified (should be return at line 29)
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    unordered_map<int, int> int_map;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index = 0;
        for(auto i: nums) {
            if(int_map.find(target - i) == int_map.end())
                int_map[i] = index++;
            else
                return vector<int>{int_map[target- i], index};
        }    
        return vector<int>();
    }
};

int main() {
    return 0;
}
