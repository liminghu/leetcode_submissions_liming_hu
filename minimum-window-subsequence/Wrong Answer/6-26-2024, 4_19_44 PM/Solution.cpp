// https://leetcode.com/problems/minimum-window-subsequence

class Solution {
public:
/*
Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.
If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple 
such minimum-length windows, return the one with the left-most starting index.
*/
    string minWindow(string s1, string s2) { //1 <= s1.length <= 2 * 104
                                            //1 <= s2.length <= 100
                                            //s1 and s2 consist of lowercase English letters.
        int sz1 = s1.length();
        int sz2 = s2.length();
        if(sz2 > sz1 )
            return "";
        
        //dp[i][j] => s[1:i]里最短的、并且包含t[1:j]的substring的长度（这个substring必须要求以s[i]结尾）
        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));
        for(int i=0; i<=sz1; i++) {
            dp[i][0] = i;
        };

        for(int i=1; i<=sz1; i++) {
            for(int j=1; j<=sz2; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int start = 0;
        int len = sz1+1;
        for(int i=1; i<=sz1; i++) {
            if(dp[i][sz2] != 0) {
                if( i-dp[i][sz2] + 1 < len ) {
                    start = dp[i][sz2] - 1;
                    len = i-dp[i][sz2] + 1;
                }
            }
        }

        if (len != sz1+1)
            return s1.substr(start+1, len-1);
        else
            return "";

    }
};