//coding:utf-8
/*****************************************
Program: First missing positive
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-17 14:54:37
Last modified: 2016-08-17 15:02:25
GCC version: 4.9.3
*****************************************/

//put every integer into corresponding position
//1 into A[1], 5 into A[5], etc

#include <vector>

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        const int n = A.size();
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);

        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
