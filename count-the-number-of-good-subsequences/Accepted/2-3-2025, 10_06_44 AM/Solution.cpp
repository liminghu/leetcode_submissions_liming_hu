// https://leetcode.com/problems/count-the-number-of-good-subsequences

class Solution {
    int M = 1e9+7;
public:
    int countGoodSubsequences(string s) {//A subsequence of a string is good if it is not empty and the frequency of each one of its characters is the same.
        vector<int> freq(26, 0);
        int n = s.length();
        long long ans = 0;
        for(char c:s)
            freq[c-'a']++;
        int maxf = 0;
        for(int f: freq) {
            maxf = max(maxf, f);
        };
        vector<vector<int>> ncr(maxf+1, vector<int>(maxf+1, 0)); //n choose r
        ncr[0][0] = 1;
        for(int i=1; i<=maxf; i++) {
            ncr[i][0] = 1;
            for(int r=1; r<=maxf; r++) 
                ncr[i][r] = ( ncr[i-1][r-1] + ncr[i-1][r] ) % M;
        };

        for(int k=1; k<=maxf; k++) {
            long long  prod = 1;
            for(int i=0; i<26; i++) {
                if(freq[i]>=k) { 
                    prod *= ( 1 + ncr[ freq[i] ][k] );//1: empty(do not choose i) + freq[i] choose k.
                    prod %= M;
                };
            }
            ans += prod-1; //-1: reduce all the empty combination
            ans %=M;
        }
        return int(ans % M);   
    }
};