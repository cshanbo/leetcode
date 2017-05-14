//coding:utf-8
/***********************************************************
Program: DFS
Description: 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-14 16:07:54
Last modified: 2017-05-14 16:17:21
GCC version: 4.9.3
***********************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<int, unordered_set<int>> p2c;
    void dfs(vector<int>& ret, unordered_map<int, unordered_set<int>>& map, int kill) {
        ret.push_back(kill);
        if (map.find(kill) == map.end())
            return;
        else {
            for(auto pid: map[kill])
                dfs(ret, map, pid);
        }
        return;
    }
public:
    vector<int> killProcess(vector<int> pid, vector<int> ppid, int kill) {
        if(pid.size() == 0)
            return vector<int>();
        vector<int> ret;
        for(int i = 0; i < pid.size(); ++i) {
            if (p2c.find(ppid[i]) == p2c.end())
                p2c[ppid[i]] = unordered_set<int>{pid[i]};
            p2c[ppid[i]].insert(pid[i]);
        }
        dfs(ret, p2c, kill);
        return ret;
    }
};

int main() {
    Solution slt;
    slt.killProcess(vector<int>{1, 2, 3, 4, 5}, vector<int>{0, 1, 1, 1, 1}, 1);
}
