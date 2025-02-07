// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) { //Given a string s, return the longest palindromic substring in s.
                                            //1 <= s.length <= 1000
                                            //s consist of only digits and English letters.
        int sz = s.length();
        int i = 0;
        int j = sz - 1;
        if( sz <= 1 )
            return s;
        
        //dp
        vector<vector<string>> dp(sz+1, vector<string>(sz+1, ""));  //dp[i][j]: i:start, j:end. longest Palindrome string.
        for(int i=0; i<sz; i++) {
            dp[i][i] = s[i];
        };

        for(int length=2; length<=sz; length++) {
            for(int i=0; i+length-1<sz; i++) {
                if( s[i] == s[i+length-1] && dp[i+1][i+length-2].length() == length - 2 )
                    dp[i][i+length-1] =s[i] + dp[i+1][i+length-2] + s[i+length-1];
                else if(dp[i][i+length-2].length() >= dp[i+1][i+length-2].length()) {
                    dp[i][i+length-1] = dp[i][i+length-2];
                } else {
                   dp[i][i+length-1] =  dp[i+1][i+length-2];
                }

               // dp[i][i+length-1]      dp[i][i+length-2]   dp[i+1][i+length-2]
            }
        }

        return dp[0][sz-1];

    }

    bool isValidPalindrome(string s, int i, int j) { //i: start; j:end
        if( i == j )
            return true;

        while( i < j ) {
            if(s[i] != s[j] )
                return false;
            i++;
            j--;
        }
        return true;

    }
};