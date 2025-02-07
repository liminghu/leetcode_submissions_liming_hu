// https://leetcode.com/problems/word-ladder-ii

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty 
list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:
1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
*/
class Solution {
public:
    unordered_set<string> wordSet;
    unordered_map<string, vector<string>> next;
    unordered_map<string, unordered_set<string>> prev;
    string beginWord;
    vector<vector<string>> res;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordSet.insert(beginWord);
        for(auto word: wordList) //put all the words in the dict.
            wordSet.insert(word);
        this->beginWord = beginWord;
        if(wordSet.find(endWord) == wordSet.end()) //endWord not found.
            return {};
        
        //build graph for next.
        for(int i=0; i<wordList.size(); i++) {
            string str = wordList[i];
            for(int k=0; k<str.length(); k++) {
                for(char ch='a'; ch<='z'; ch++) {
                    string temp = str;
                    temp[k] = ch;
                    if(temp == str)
                        continue;
                    if( wordSet.find(temp) != wordSet.end() ) 
                        next[str].push_back(temp);
                }
            }
        };

        unordered_set<string> visited;
        queue<string> q;
        int found = 0;
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty()) {  //BFS to build prev
            int size = q.size();
            unordered_set<string> newVisited;
            for(int k=0; k<size; k++) {
                string str = q.front();
                q.pop();
                for(auto nextStr: next[str]) {
                    if(visited.find(nextStr) != visited.end()) //nextStr has been visited before.
                        continue;
                    prev[nextStr].insert(str);
                    newVisited.insert(nextStr);
                    if( nextStr == endWord )
                        found = 1;
                }
            }
            for(auto item: newVisited) {
                visited.insert(item);
                q.push(item);
            }
            if( found == 1 )
                break;
        }
        
        if( found == 0 )
            return {};
        
        DFS(endWord, {endWord});
        return res;
    }

    void DFS(string word, vector<string> path) {
        if(word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }

        for(auto preStr: prev[word]) {
            vector<string> newPath = path;
            newPath.push_back(preStr);
            DFS(preStr, newPath);
        }
        return;
    }
};