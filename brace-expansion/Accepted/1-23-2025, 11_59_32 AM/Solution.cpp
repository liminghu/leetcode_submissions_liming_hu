// https://leetcode.com/problems/brace-expansion

class Solution {
vector<vector<char>> allOptions;
public:
    vector<string> expand(string s) {
        storeAlloptions(s);
        vector<string> expandedWords;
        generateWords("", expandedWords);
        return expandedWords;
    }
    void storeAlloptions(string s) {
        int i=0;
        while(i<s.size()) {
            vector<char> curOptions;
            if(s[i]!= '{') {
                curOptions.push_back(s[i]);
            } else {  //'{'
                while( i<s.size() && s[i]!='}') {
                    if(islower(s[i]))
                        curOptions.push_back(s[i]);
                    i++;
                }
                //s[i] == '}'
                sort(curOptions.begin(), curOptions.end());
            }
            allOptions.push_back(curOptions);
            i++;
        }
    }
    void generateWords(string curWord, vector<string>& expandedWords) {
        if(curWord.size() == allOptions.size()) {
            expandedWords.push_back(curWord);
            return;
        }
        vector<char> curOptions = allOptions[curWord.size()];
        for(char c: curOptions) {
            curWord += c;
            generateWords(curWord, expandedWords);
            curWord.pop_back(); //backtracking...
        }

    }
};