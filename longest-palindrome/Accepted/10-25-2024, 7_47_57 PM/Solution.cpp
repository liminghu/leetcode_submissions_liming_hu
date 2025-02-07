// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> dictL(26, 0);
        vector<int> dictU(26, 0);
        for(int i=0; i<s.length(); i++) {
            if(islower(s[i]))
                dictL[s[i]-'a']++;
            else
                dictU[s[i]-'A']++;
        };

        int ret = 0;
        int hasOdd = 0;
        for(int i=0; i<26; i++) {
            if(dictL[i] % 2 == 0)
                ret += dictL[i];
            else {
                hasOdd = true; //odd.
                ret += dictL[i] -1;
            }
            if(dictU[i] % 2 == 0)
                ret += dictU[i];
            else {
                hasOdd = true; //odd.
                ret += dictU[i] -1;
            }
        };

        return ret +( hasOdd? 1: 0);
    }
};