// https://leetcode.com/problems/valid-word-abbreviation

/*
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
The following are not valid abbreviations:

"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)
Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.
*/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        /*
            1 <= word.length <= 20
            word consists of only lowercase English letters.
            1 <= abbr.length <= 10
            abbr consists of lowercase English letters and digits.
            All the integers in abbr will fit in a 32-bit integer.
        */
        int sz = word.length();
        int a_sz = abbr.length();
        int i = 0;
        int j = 0;
        while( i < sz  && j < a_sz) {
            if( word[i] == abbr[j] ) {
                i++; j++;
            } else {
                if(abbr[j]>='0' && abbr[j]<='9') {
                    int digit = 0;
                    while(abbr[j]>='0' && abbr[j]<='9' && j < a_sz) {
                        if(abbr[j]=='0' && digit == 0) {
                            return false;
                        } else {
                            digit = digit*10+abbr[j]-'0';
                            j++;
                        }
                    }
                    i = i + digit;
                } else 
                    return false;
            }

        }

        if(i==sz && j==a_sz)
            return true;
        else
            return false;
    }
};