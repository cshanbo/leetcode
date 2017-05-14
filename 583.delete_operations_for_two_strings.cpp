//coding:utf-8
/***********************************************************
Program: 583
Description: find the longest common substring, and then count the operations 
Shanbo Cheng: cshanbo@gmail.com
Date: 2017-05-14 16:48:32
Last modified: 2017-05-14 16:49:07
GCC version: 4.9.3
***********************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.length(); ++i)
            for (int j = 0; j <= word2.length(); ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else 
                    dp[i][j] = (word1[i-1] == word2[j-1])? dp[i-1][j-1]+1: max(dp[i-1][j], dp[i][j-1]);
            }
        return word1.length() + word2.length() - 2 * dp[word1.length()][word2.length()];
    }
};
