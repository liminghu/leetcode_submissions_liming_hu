// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing 
the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/
    int longestCommonSubsequence(string text1, string text2) { //1 <= text1.length, text2.length <= 1000
                                                                //text1 and text2 consist of only lowercase English characters.
        int sz1 = text1.length();
        int sz2 = text2.length();

        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = 0;

        for(int i=0; i<sz1; i++) {
             for(int j=0; j<sz2; j++) {
                if(text1[i]==text2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max( dp[i][j+1],  dp[i+1][j]);
             }
        }
        return dp[sz1][sz2];

        
    }
};