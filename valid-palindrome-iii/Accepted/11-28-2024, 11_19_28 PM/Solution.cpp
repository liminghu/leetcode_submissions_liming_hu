// https://leetcode.com/problems/valid-palindrome-iii

class Solution {
public:
    bool isValidPalindrome(string s, int k) {//removing at most k characters from it.
        int n = s.length();
        if(k==n || k == n-1)
            return true;
        //dp[i][j]: minimum removal required to make string s[i~j] a palindrome.
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //1, Clearly that if j-i+1<=1 (empty string or one character string) then dp[i][j] = 0. This becomes a base case of the problem.
        //2, For dp[i][j] where j-i+1 >= 2, we can compare s[i] with s[j]. If s[i] = s[j], then we don't need to removal them.
        // Otherwise, the answer is dp[i+1][j] or dp[i][j-1], whichever is smaller, plus 1 as a necessary removal to remove either s[i] or s[j].
        //So here's the induction steps: dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1
        for(int j=0; j<n; j++) {
            for(int i=j-1; i>=0; i--) {
                if(j-i == 1)
                    dp[i][j] = (s[i]==s[j]? 0: 1);
                else {
                    if(s[i]==s[j]) {
                        dp[i][j] = dp[i+1][j-1];
                    } else {
                        dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;
                    }
                }
            }
        }
        return dp[0][n-1] <=k;
    }
};