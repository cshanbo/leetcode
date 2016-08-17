//coding:utf-8
/***********************************************************
Program: Shuffle an array
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2016-08-12 21:56:33
Last modified: 2016-08-12 21:59:06
GCC version: 4.9.3
***********************************************************/

#include <vector>
#include <random>
using namespace std;

//the idea is simple
//The idea is simple,  just using two vectors to store the numbers,  one is original,  one is to be shuffled.
//The shuffle algorithm is the Knuth Shuffle:
//
//Randomly choose a value in the vector from 0 ... size. (size is initialized of vector.size() - 1)
//Swap the value with the size-th last value of the vector
//Reduce the size by 1.
//Go to 1 while size > 0
//
class Solution {
    vector<int> original;
    vector<int> shuf;
public:
    Solution(vector<int> nums) {
        original = nums;
        shuf = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(shuf.empty())
            return shuf;
        for(int i = shuf.size(); i > 0; --i)
            swap(shuf[rand() % i], shuf[i - 1]);
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
