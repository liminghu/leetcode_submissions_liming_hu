// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.
*/
    int numDistinct(string s, string t) { //1 <= s.length, t.length <= 1000; s and t consist of English letters.
        int sz1 = s.length();
        int sz2 = t.length();
        if( sz2 > sz1 )
            return 0;

        //dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
        vector<vector<uint64_t>> dp(sz1+1, vector<uint64_t>(sz2+1, 0));
        for(int i=0; i<=sz1; i++)
            dp[i][0] = 1;
        for(int j=1; j<=sz2; j++)
            dp[0][j] = 0;    

        for(int i=1; i<=sz1; i++) {
            for(int j=1; j<=sz2; j++) {
                if( s[i-1] == t[j-1] ) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[sz1][sz2];
        
    }
};