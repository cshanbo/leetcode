#include <iostream>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (!n)
            return 0;
        if (n <= 3)
            return 1;
        vector<int> a(n+1);
        a[0] = 1;
        a[1] = 2;
        a[2] = 2;
        int head = 2, tail = 3, num = 1, result = 1;
        while (tail < n) {
            for (int i = 0; i < a[head]; ++i) {
                a[tail] = num;
                if (num == 1 && tail < n)
                    result++;
                tail++;
            }
            num ^= 3;
            head++;
        }
        return result;
    }
};
