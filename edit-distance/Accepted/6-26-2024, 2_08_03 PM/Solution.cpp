// https://leetcode.com/problems/edit-distance

class Solution {
public:
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
*/
    int minDistance(string word1, string word2) { //0 <= word1.length, word2.length <= 500
        int sz1 = word1.size();
        int sz2 = word2.size();
        if(sz1==0)
            return sz2;
        if(sz2==0)
            return sz1;

        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));
        dp[0][0] = 0;
        //dp[0][1] = 1;
        //dp[1][0] = 1;
        for(int i=0; i<=sz1; i++)
            dp[i][0] = i;
        for(int j=0; j<=sz2; j++)
            dp[0][j] = j;

        for(int i=1; i<=sz1; i++) {
            for(int j=1; j<=sz2; j++) {
                if(word1[i-1] == word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    //insert, delettion, replace
                    int minPre = min(dp[i-1][j]+1, dp[i][j-1]+1);
                    minPre = min(minPre, dp[i-1][j-1]+1);
                    dp[i][j] = minPre;
                }
            } 
        }
        return dp[sz1][sz2];

       // return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

/*    int minDistanceRecur(string word1, string word2, int word1Index, int word2Index) {
        if( word1Index == 0)
            return word2Index;
        if( word2Index == 0)
            return word1Index;
        
        if(word1[word1Index-1] == word2[word2Index-1] ) 
            return minDistanceRecur(word1, word2, word1Index-1, word2Index-1);
        else {
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            return min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
        }
    }*/
};