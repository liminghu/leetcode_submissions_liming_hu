// https://leetcode.com/problems/minimum-window-subsequence

class Solution {
public:
/*
Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.
If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple 
such minimum-length windows, return the one with the left-most starting index.
*/

//https://www.cnblogs.com/grandyang/p/8684817.html
    string minWindow(string S, string T) { //1 <= s1.length <= 2 * 104
                                            //1 <= s2.length <= 100
                                            //s1 and s2 consist of lowercase English letters.
    /*
    Let dp(i, j) stores the "largest" starting index (make the length smallest) of the valid substring W of S[0, i] 
    such that T[0, j] is a subsequence of S. Otherwise, dp(i, j) = -1; So dp(i, j) would be:

    if S[i] == T[j], this means we could borrow the start index from dp(i-1, j-1) to make the current substring valid;
    else, we only need to borrow the start index from dp(i-1, j) which could either exist or not.

    Finally, go through the last col to find the substring with min length and appears first.
    */
      int len_S = S.length();
        int len_T = T.length();
        
        // initialize all value to -1
        vector<vector<int>> dp(len_S, vector<int>(len_T, -1));
        
        // initialize the first col
        for (int i=0; i<len_S; i++) {
            if (S[i] == T[0]) {
                dp[i][0] = i;
            } else {
                if (i != 0) {
                    dp[i][0] = dp[i-1][0];
                }
            }
        }
        
        // calculate dp[][]
        for (int i=1; i<len_S; i++) {
            for (int j=1; j<len_T; j++) {
                if (S[i] == T[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // Finally, go through the last col to find the substring with min length and appears first.
        int begin = -1, min_len = INT_MAX;
        for (int i=0; i<len_S; i++) {
            int index = dp[i][len_T-1];
            if (index != -1) {
                if (i + 1 - index < min_len) {
                    begin = index;
                    min_len = i + 1 - index;
                }
            }
        }
        return begin == -1 ? "" : S.substr(begin, min_len);
    }
};