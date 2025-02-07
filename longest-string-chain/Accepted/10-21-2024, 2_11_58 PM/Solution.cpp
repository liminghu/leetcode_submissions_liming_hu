// https://leetcode.com/problems/longest-string-chain

/*
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order 
of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is 
a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list of words.

 Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 
Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n<=1)
            return n;
        
        unordered_map<string, int> dp; //the length of the longest possible word chain with word string
        vector<vector<string>> wordList(17, vector<string>());
        for(int i=0; i<n; i++) {
            int len = words[i].length();
            wordList[len].push_back(words[i]);
            dp[words[i]] = 1;
        }    

        int max_chain = 1;
        for(int len=1; len<17; len++) {
            if(wordList[len].size() == 0)
                continue;
            for(string word: wordList[len]) {
                int preLen = len -1;
                if(wordList[preLen].size()==0) 
                    break;
                for(string preWord: wordList[preLen]) {
                    if(predecessor(preWord, word)) {
                        dp[word] = max(dp[word], dp[preWord]+1);
                        max_chain = max(max_chain, dp[word]);
                    }
                }
            }
        };
        return max_chain;         
    }
    //wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
    bool predecessor(string wordA, string wordB) {
        int n = wordA.length();
        int m = wordB.length();
        if(n != m-1)
            return false;
        
        unordered_set<string> dict;
        //cout << "wordB: " << wordB << endl;
        for(int i=0; i<m; i++) {
            string newB = wordB;
            newB.erase(newB.begin()+i);
            dict.insert(newB);
            //cout<< "newB: " << newB << endl;
        }
        //cout << "wordA: " << wordA << endl;
        return dict.contains(wordA);
    }
};