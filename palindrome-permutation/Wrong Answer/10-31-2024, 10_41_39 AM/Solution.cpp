// https://leetcode.com/problems/palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> dict(26, 0);
        for(int i=0; i<s.length(); i++) 
            dict[ s[i]-'a' ]++;
        int oddCount = 0;
        for(int i=0; i<26; i++) {
            if( dict[i] % 2 == 1 )
                oddCount++;
        }
        return oddCount % 2 == 1;
    }
};