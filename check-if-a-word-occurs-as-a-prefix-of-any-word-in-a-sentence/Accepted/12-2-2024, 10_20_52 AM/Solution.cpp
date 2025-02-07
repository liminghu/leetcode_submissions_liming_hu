// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        int idx = 1;
        string word;
        while( iss>>word ) {
            if(isPrefix(word, searchWord))
                return idx;
            idx++;
        }
        return -1;
    }
    
    bool isPrefix(string word, string searchWord) {
        if(searchWord.size() > word.size())
            return false;
        for(int i=0; i<searchWord.size(); i++) {
            if(word[i]!= searchWord[i])
                return false;
        };
        return true;
    }
};