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
    int minDistance(string word1, string word2) {
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string word1, string word2, int word1Index, int word2Index) {
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

    }
};