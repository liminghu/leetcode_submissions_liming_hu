// https://leetcode.com/problems/reverse-vowels-of-a-string

/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i]))
                vowels.push_back(s[i]);
        };
        reverse(vowels.begin(), vowels.end());
        string ret = "";
        int j=0;
        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i])) {
                ret.push_back(vowels[j++]);
            } else {
                ret.push_back(s[i]);
            }
        };
        return ret;
    }

    bool isVowel(char c) {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u')
            return true;
        else
            return false;
    }
};