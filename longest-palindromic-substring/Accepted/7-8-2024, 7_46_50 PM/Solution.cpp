// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) { //Given a string s, return the longest palindromic substring in s.
                                            //1 <= s.length <= 1000
                                            //s consist of only digits and English letters.
        int sz = s.length();
        if( sz <= 1 )
            return s;
        
        //dp
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));  //dp[i][j]: i:start, j:end. is s[i.,.j]  valid Palindrome string?
        for(int i=0; i<sz; i++) {
            dp[i][i] = true;
        };

        int start = 0;
        int end = 0;
        for(int i = 0; i < sz-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                end = i + 1;
            }
        }


        for ( int length = 3; length <= sz; length++ ) {
            for ( int i = 0; i + length - 1 < sz; i++ ) {
                if( s[i] == s[ i + length - 1 ] && dp[ i+1 ][ i+length-2 ] ) {
                    dp[i][i+length-1] = true;
                    start = i;
                    end = i+length-1;
                }
            }
        }

        return s.substr(start, end-start+1);

    }
};