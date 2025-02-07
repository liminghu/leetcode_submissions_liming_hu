// https://leetcode.com/problems/word-ladder

class Solution {
public:
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/
    int distance(string first, string second) {
        int ans = 0;
        for(int i=0; i<first.size(); i++) {
            if(first[i]!=second[i])
                ans++;
        };
        return ans; 
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        wordList.push_back(beginWord);
        int n = wordList.size();
        unordered_map<string, bool> visited;
        for(int i=0; i<n; i++) {
            visited[wordList[i]] = false;
        };


        if(visited.find(endWord) == visited.end()) 
            return 0;
        
        queue<string> trans_q;
        trans_q.push(endWord);
        int count = 0;
        while(!trans_q.empty()) {
            count++;
            int sz = trans_q.size();
            while(sz--) {
                string cur = trans_q.front();
                visited[cur] = true;
                trans_q.pop();
            
                //find cur's next, and push them into the queue.
                for(int i=0; i<n; i++) {
                    if(visited[wordList[i]] !=true && distance(cur, wordList[i])==1) {
                        trans_q.push(wordList[i]);
                    };
                };
            };
        };
        
        return count;
    }
};