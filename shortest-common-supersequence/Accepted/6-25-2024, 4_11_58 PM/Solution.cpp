// https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
*/
    string shortestCommonSupersequence(string str1, string str2) {//1 <= str1.length, str2.length <= 1000; str1 and str2 consist of lowercase English letters.
        int sz1= str1.length();
        int sz2 = str2.length();
        string res = "";

        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0)); //compute LCS length 
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        for(int i=0; i<sz1; i++) {
            for(int j=0; j<sz2; j++) {
                if(str1[i] == str2[j]) 
                    dp[i+1][j+1] = dp[i][j]+1;
                else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
       
       int i=sz1, j=sz2;
       while(i>0 && j>0) { //print LCS
            if(str1[i-1]==str2[j-1]) {
                res.push_back(str1[i-1]);
                i--;
                j--;
            }else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    res.push_back(str1[i-1]);
                    i--;
                }else {
                    res.push_back(str2[j-1]);
                    j--;
                }
            }
       }

        while(i>0) {
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0) {
            res.push_back(str2[j-1]);
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    
    }
};