// https://leetcode.com/problems/lexicographically-smallest-beautiful-string

/*
A string is beautiful if:
It consists of the first k letters of the English lowercase alphabet.
It does not contain any substring of length 2 or more which is a palindrome.
You are given a beautiful string s of length n and a positive integer k.
Return the lexicographically smallest string of length n, which is larger than s and is beautiful. If there is no such string, 
return an empty string.
A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a 
has a character strictly larger than the corresponding character in b.
For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, 
and d is greater than c.
 
Example 1:
Input: s = "abcz", k = 26
Output: "abda"
Explanation: The string "abda" is beautiful and lexicographically larger than the string "abcz".
It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically 
smaller than the string "abda".

Example 2:
Input: s = "dc", k = 4
Output: ""
Explanation: It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.
 
Constraints:
1 <= n == s.length <= 105
4 <= k <= 26
s is a beautiful string.
*/
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.length();
        string original = s;
        int flag = 0;
        for(int i=n-1; i>=0; i--) {
            for(char ch=s[i]+1; ch<'a'+k; ch++) {
                if(!checkOK(s, i, ch)) 
                    continue;
                s[i] = ch;
                for(int j = i+1; j<n; j++) {
                    for(char c='a'; c<'a'+k; c++) {
                        if(checkOK(s, j, c)) {
                            s[j] = c;
                            break;
                        }
                    }
                }
                flag = 1;
                break;            
            }
            if(flag)
                break;
        }
        if(s == original) 
            return "";
        return s;
    }
    bool checkOK(string& s, int i, char ch) {
        if(i>=1 && s[i-1] == ch)
            return false;
        if(i>=2 && s[i-2] == ch)
            return false;
        return true;
    }
};