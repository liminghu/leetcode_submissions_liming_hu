// https://leetcode.com/problems/regular-expression-matching

/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/
class Solution {
private:
    vector<vector<int>> dp; 
public:
    bool isMatch(string s, string p) {
        /*
        1 <= s.length <= 20
        1 <= p.length <= 20
        s contains only lowercase English letters.
        p contains only lowercase English letters, '.', and '*'.
        It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
        */

        //dp
        // does text[i:] and pattern[j:] match?
        dp = vector(s.length()+1, vector<int>(p.length()+1, -1)); //0: no-match, 1: match, -1: do not know 
        bool result = false;
        result = solve(s, p, 0, 0); //0: start of s, 0: start of p. 
        return result;
    }
    bool solve(string s, string p, int end_s, int end_p) {
        bool result = false;

        if(dp[end_s][end_p] != -1)
            return dp[end_s][end_p] == 1;
        
        if(end_p == p.length()) //to the end of pattern.
            return end_s == s.length(); //is the string at the end?
        else {
             bool first_match = (end_s < s.length() && (p[end_p] == s[end_s] || p[end_p] == '.'));

             if (end_p + 1 < p.length() && p[end_p + 1] == '*') {
                result = ( solve(s, p, end_s, end_p + 2) //match zero of the preceding element.
                || (first_match && solve( s, p, end_s + 1, end_p )) ); //Matches more of the preceding element.
            } else { //no *
                result = first_match && solve(s, p, end_s + 1, end_p + 1);
            }
        }

        dp[end_s][end_p] = result;

        return result;

    }
};