// https://leetcode.com/problems/count-the-number-of-special-characters-i

class Solution {
public:
    int numberOfSpecialChars(string word) { //word consists of only lowercase and uppercase English letters.
        int dict_lower[26];
        int dict_upper[26];
        for(int i=0; i<word.length(); i++) {
            if(word[i]>='a' & word[i]<='z') 
                dict_lower[word[i]-'a']++;
            else
            dict_upper[word[i]-'A']++;
        };

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(dict_lower[i]>0 & dict_upper[i]>0)
                ans++;
        };

        return ans; 
        
    }
};