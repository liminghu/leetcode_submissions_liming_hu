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
         unordered_map<string, vector<int>> mp;
        for(int i=0; i<wordsDict.size(); i++) {
            mp[wordsDict[i]].push_back(i);
        };
        vector<int> w1_locs = mp[word1];
        vector<int> w2_locs = mp[word2];
        int min_dist = INT_MAX;
        if(word1!=word2) {
            for(int i=0; i<w1_locs.size(); i++) {
                for(int j=0; j<w2_locs.size(); j++) {
                    min_dist = min(min_dist, abs(w1_locs[i]-w2_locs[j]) );
                }
            }    
        } else {
            for(int j=1; j<w1_locs.size(); j++) {
                min_dist = min(min_dist, abs(w1_locs[j]-w1_locs[j-1]) );
            }
        }
        return min_dist;        
    }
};