// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

class Solution {
public:
    int appendCharacters(string s, string t) { //two strings s and t consisting of only lowercase English letters.
    //Return the minimum number of characters that need to be appended to the end of s 
    //so that t becomes a subsequence of s.
    //A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<t.length()) {
            if(i<s.length() && s[i]==t[j]) {
                i++; 
                j++;
                continue;
            } else if (i<s.length() && s[i]!=t[j]) {
                i++;
                continue;
            } else if(i==s.length() ) {
                ans = t.length() - j;
                break;
            }
        }
        return ans;
    }
};