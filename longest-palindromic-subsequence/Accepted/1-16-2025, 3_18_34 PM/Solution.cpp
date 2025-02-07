// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0)); //the longest palindromic subsequence's length of substring(i, j), here i, j represent left, right indexes in the string

        for(int i=n-1; i>=0; i--) {
            dp[i][i] = 1;
            for(int j=i+1; j<n; j++) {
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};