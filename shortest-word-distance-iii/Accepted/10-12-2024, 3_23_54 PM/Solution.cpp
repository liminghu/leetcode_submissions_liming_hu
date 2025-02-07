// https://leetcode.com/problems/shortest-word-distance-iii

/*
Given an array of strings wordsDict and two strings that already exist in the array word1 and word2, 
return the shortest distance between the occurrence of these two words in the list.
Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3
 

Constraints:
1 <= wordsDict.length <= 105
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
*/
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = INT_MAX;
        int prevIndx = -1;
        for(int i=0; i<wordsDict.size(); i++) {
            if(wordsDict[i]== word1 || wordsDict[i] == word2) {
                //if prevIndx is present and pointing to a different string that the string at the current index.
                if(prevIndx !=-1 && (wordsDict[prevIndx] != wordsDict[i] || word1 == word2) ) {
                    res = min(res, i-prevIndx);
                }
                prevIndx = i;
            }
        }
        return res;
    } 

};