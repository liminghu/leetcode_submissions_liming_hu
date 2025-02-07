// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> dict(26, 0);
        for(char c:s) 
            dict[c-'a']++;
        if(s.length()<k)
            return false;
        if(s.length() == k)
            return true;
        int nodd = 0;
        int neven = 0;
        for(int i=0; i<26; i++) {
            if(dict[i]%2 == 1)
                nodd++;
            neven += dict[i]/2;
        }
        if(nodd>k)
            return false;

        return true;
    }
};