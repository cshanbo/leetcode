//coding:utf-8
/***********************************************************
* Program: Heap Sort
* Description:
* Author: Shanbo CHENG
* Date: 2016-01-18 19:26:38
* Last modified: 2016-01-18 19:49:01
***********************************************************/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
 * parameter 'index' is the index of the start of unsorted part
 * parameter 'last' is the index of the last element in heap array
 */
void heapFixDown(vector<int>& vec, int index, int last) {
    int child = index * 2 + 1;
    while(child <= last) {
        if(child + 1 <= last && vec[child] > vec[child + 1])
            child++;
        if(vec[index] < vec[child])
            break;
        swap(vec[child], vec[index]);
        index = child;
        child = index * 2 + 1;
    }
    return;
}

void deleteElement(vector<int>& vec, int start) {
    heapFixDown(vec, start, vec.size() - 1);
    return;
}

void makeHeap(vector<int>& vec) {
    if(!vec.size())
        return;
    const int sz = vec.size();
    for(int i = sz/ 2 - 1; i >= 0; i--)
        heapFixDown(vec, i, sz - 1);
}

int main() {
    vector<int> vec{5, 8, 1, 3, 2};
    const int sz = vec.size();
    makeHeap(vec);

    for(int i = sz - 1; i >= 0; i--) {
        swap(vec[0], vec[i]);
        heapFixDown(vec, 0, i - 1);
    }
    for(auto i: vec)
        cout << i << " ";
}
