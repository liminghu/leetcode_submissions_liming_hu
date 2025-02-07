// https://leetcode.com/problems/keyboard-row

class Solution {
char dict1[26];
char dict2[26];
char dict3[26];
public:
    vector<string> findWords(vector<string>& words) {
        string f = "qwertyuiop";
        string s = "asdfghjkl";
        string t = "zxcvbnm";
                
        for(char c: f) {
            dict1[c-'a']++;
        };
        for(char c: s) {
            dict2[c-'a']++;
        };
        for(char c: t) {
            dict3[c-'a']++;
        };
        vector<string> rets;
        for(int i=0; i<words.size(); i++) {
            if(inOneRow(words[i]))
                rets.push_back(words[i]);
        }
        return rets;
    }
    bool inOneRow(string word) {

        if(word.size()<=1)
            return true;
        int i=1;
        while(i<word.size()) {
            word[i] = tolower(word[i]);
            word[i-1] = tolower(word[i-1]);
            if((dict1[word[i]-'a'] == dict1[word[i-1]-'a']) && (dict2[word[i]-'a'] == dict2[word[i-1]-'a'])  && (dict3[word[i]-'a'] == dict3[word[i-1]-'a']) ) {
                i++;
                continue;
            } else
                return false;
            i++;
        }
        return true;
    }
};