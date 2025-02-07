// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) { //Given a string s, return the longest palindromic substring in s.
                                            //1 <= s.length <= 1000
                                            //s consist of only digits and English letters.
        int sz = s.length();
        int i = 0;
        int j = sz - 1;
        if( sz <= 1 )
            return s;
        
        string ans = "";
        while( i < j ) {
            if( s[i] != s[j] ) {
                i++;
                j--;
            } else if (isValidPalindrome(s, i, j)) {
                return s.substr(i, j-i+1);
            } else {
                i++;
                j--;
            };
        }

        return s.substr(i,1);

    }

    bool isValidPalindrome(string s, int i, int j) { //i: start; j:end
        if( i == j )
            return true;

        while( i < j ) {
            if(s[i] != s[j] )
                return false;
            i++;
            j--;
        }
        return true;

    }
};