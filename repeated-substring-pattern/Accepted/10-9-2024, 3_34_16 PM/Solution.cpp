// https://leetcode.com/problems/repeated-substring-pattern

/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.

*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len ==1 )
            return false;
        for(int i=len/2; i>=1; i--) { //length of the substring
            string buildStr;
            if(len % i == 0) {
                int grpNum = len / i;
                string sub = s.substr(0,i);
                for(int j=0; j<grpNum; j++)
                    buildStr += sub;
            }
            if( s == buildStr )
                return true;
        }
        return false;
    }
};