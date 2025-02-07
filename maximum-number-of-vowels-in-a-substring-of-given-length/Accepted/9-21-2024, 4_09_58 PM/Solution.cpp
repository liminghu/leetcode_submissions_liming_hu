// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int ret = 0;
        int n = s.length();
        int count = 0;
        for(int i=0; i<k; i++) {
            if(isVowel(s[i]))
                count++;
        };
        ret = count;
        for(int i=k; i<n; i++) {
            if(isVowel(s[i-k]))
                count--;
            if(isVowel(s[i]))
                count++;
            ret = max(ret, count);
        }
        return ret;
    }

    bool isVowel(char c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        else
            return false;
    }
};