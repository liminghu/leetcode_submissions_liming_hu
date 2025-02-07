// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

/*
Given two strings needle and haystack, return the index 
of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = haystack;
        string p = needle;
        int n = s.size();
        int m = p.size();

        if( m == 0 ) 
            return 0;
        if( n == 0)
            return -1;
        vector<int> dp(n,0);
        dp[0] = (s[0] == p[0]);
        if( m == 1 && s[0] == p[0])
            return 0;
        vector<int> suffix = preprocess(p);
        for(int i=1; i<n; i++) {
            int j = dp[i-1];
            while(j>=1 && s[i] != p[j]) {
                j = suffix[j-1];
            }
            dp[i] = j+ (s[i] == p[j]);
            if(dp[i] == p.size()) 
                return i-p.size()+1; 
        }
        return -1;
    }

    //suffix
    vector<int> preprocess(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 0;

        for(int i=1; i<n; i++) {
            int j = dp[i-1];
            while(j>=1 && s[j] != s[i]) {
                j = dp[j-1];
            }
            dp[i] = j+ (s[j] == s[i]);
        }
        return dp;
    }
};