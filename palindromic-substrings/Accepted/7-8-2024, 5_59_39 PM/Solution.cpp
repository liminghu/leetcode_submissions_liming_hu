// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
*/
    int countSubstrings(string s) { //1 <= s.length <= 1000
        int sz = s.length();
        if( sz <= 1 )
            return sz;
        
        //dp
        vector<vector<int>> dp(sz+1, vector<int>(sz+1, 0));   //dp[i][j]: numbers of valid palindroic strings from start i to end j.
        for(int i=0; i<sz; i++) {
            dp[i][i] = 1;   //length is 1.
        };

        for(int length=2; length<=sz; length++) {  //3
            for(int i=0; i+length-1<sz; i++) { //start. //0+3-1<3
                dp[i][i+length-1] = dp[i][i+length-2]+dp[i+1][i+length-1]- dp[i+1][i+length-2]+isValidPalindromic(s, i, i+length-1);
            }
        };

        return dp[0][sz-1];        
    }

    int isValidPalindromic(string s, int start, int end) {
        
        if(start == end)
            return 1;
        while( start < end ) {
            if(s[start]!= s[end])
                return 0;
            start++;
            end--;
        }
        return 1;
    }
};