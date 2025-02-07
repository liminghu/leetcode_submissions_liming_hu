// https://leetcode.com/problems/shortest-word-distance

/*
Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, 
return the shortest distance between these two words in the list.

Example 1:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3

Example 2:
Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
 

Constraints:
2 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
*/
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> mp;
        for(int i=0; i<wordsDict.size(); i++) {
            mp[wordsDict[i]].push_back(i);
        };
        vector<int> w1_locs = mp[word1];
        vector<int> w2_locs = mp[word2];
        int min_dist = INT_MAX;
        for(int i=0; i<w1_locs.size(); i++) {
            for(int j=0; j<w2_locs.size(); j++) {
                min_dist = min(min_dist, abs(w1_locs[i]-w2_locs[j]) );
            }
        }    
        return min_dist;    
    }
};