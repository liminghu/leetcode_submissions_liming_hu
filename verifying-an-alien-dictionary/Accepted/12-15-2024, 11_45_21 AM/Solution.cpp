// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
    char dict[26];
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<order.length(); i++) {
            dict[ order[i]-'a'] = i;
        };
        for(int i=0; i<words.size()-1; i++) {
            if(compareWord(words[i], words[i+1]))
                continue;
            else
                return false;
        }
        return true;
    }
    bool compareWord(string a, string b) {
        int i=0;
        int j = 0;
        while(i<a.length() && j<b.length()) {
            if(dict[a[i]-'a'] == dict[b[j]-'a']) {
                i++;
                j++;
            } else 
                return dict[a[i]-'a'] < dict[b[j]-'a'];
        };
        return a.length() <= b.length();
    }
};