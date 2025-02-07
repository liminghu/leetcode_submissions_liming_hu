// https://leetcode.com/problems/count-the-number-of-consistent-strings

/*
You are given a string allowed consisting of distinct characters and 
an array of strings words. A string is consistent if all characters 
in the string appear in the string allowed.
Return the number of consistent strings in the array words.
1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
*/
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> letter_dict(26, 0); //lowercase English letters.
        for(int i=0; i<allowed.length(); i++) {
            int c = allowed[i]-'a';
            letter_dict[c]++;
        };
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            int k=0;
            while(k<word.length()) {
                if(letter_dict[word[k]-'a'] > 0) {
                    k++;
                    continue;
                } else 
                    break;
            };
            if(k==word.length())
                ans++;
        };
        return ans; 
    }
};