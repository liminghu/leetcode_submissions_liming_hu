// https://leetcode.com/problems/minimum-window-subsequence

class Solution {
public:
/*
Given strings S and T, return the minimum contiguous substring part of S, so that T is a subsequence of the part.
If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple 
such minimum-length windows, return the one with the left-most starting index.
*/
    string minWindow(string S, string T) { //1 <= S.length <= 2 * 104
                                            //1 <= T.length <= 100
                                            //S and T consist of lowercase English letters.
        int S_len = S.length();
        int T_len = T.length();

        //minimum contiguous substring part of S, so that T is a subsequence of the part.
        vector<vector<int>> dp(S_len+1, vector<int>(T_len+1, 0)); //length.
        for(int j=1; j<=T_len; j++)
            dp[0][j] = INT_MAX/2; //if S_len is 0 and T_len is non-zero, there is no way we can find a sunstring.
        
        for(int i=1; i<=S_len; i++) {
            for(int j=1; j<=T_len; j++) {
                if( S[i-1] == T[j-1] ) 
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = dp[i-1][j]+1;
            }
        } //end for

        int min_len = INT_MAX/2;
        int end_pos = -1;
        for(int i=0; i<S_len; i++) {
            if(dp[i][T_len] < min_len) {
                min_len = dp[i][T_len];
                end_pos = i-1;
            }
        }

        if (min_len == INT_MAX/2)
            return "";
        
        return S.substr(end_pos-min_len+1, min_len);

    }
};