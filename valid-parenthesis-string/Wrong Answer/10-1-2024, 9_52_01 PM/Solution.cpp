// https://leetcode.com/problems/valid-parenthesis-string

/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
1 <= s.length <= 100
s[i] is '(', ')' or '*'. 
*/
class Solution {
public:
    bool checkValidString(string s) {
        int countMax = 0; //max # of unmatched '(', try to use * as '(' if possible.
        int coutMin = 0;  //min # of unmatched '(', try to use * as ')' if possible. 
        for(auto ch: s) {
            if(ch=='(') {
                countMax++;
                coutMin++;
            } else if(ch==')') {
                countMax--;
                coutMin--;                
            } else {
                countMax++;
                coutMin--;
                if(countMax < 0 )
                    return false;                    
            }
        }
        return coutMin <= 0;
    }
};