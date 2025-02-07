// https://leetcode.com/problems/wildcard-matching

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        s = '#' + s;
        p = '#' + p;
        //the matching p[0...j] can cover the input string s[0...i]?
        vector<vector<int>> dp(m+1, vector(n+1, 0));

        dp[0][0] = 1; //# matches #
        //dp[0][j]:  if p[j] == '*'
        for(int j=1; j<=n; j++) {
            if(p[j] != '*')
                break;
            dp[0][j] = 1;
        }
        //dp[i][0]: it will be all 0.

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(p[j] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(s[i]==p[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j] == '*') {
                    for(int k=0; k<=i; k++) {
                        if(dp[k][j-1] == 1)
                            dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};