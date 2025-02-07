// https://leetcode.com/problems/longest-happy-prefix

/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
1 <= s.length <= 105
s contains only lowercase English letters.
*/
class Solution {
public:
    string longestPrefix(string s) {
        int sz = s.length();
        vector<int> dp(sz,0); // dp[i]: the max lenth k s.t. s[0, k-1] = s[i-k+1, i]
        dp[0] = 0; 
        for(int i=1; i<sz; i++) {
            int j = dp[i-1];
            while( j>=1 && s[j] != s[i] ) {
                j = dp[j-1];                
            }
            dp[i] = j + (s[i] == s[j]);
        }

        int len = dp[sz-1];
        return s.substr(0, len);
    }
};