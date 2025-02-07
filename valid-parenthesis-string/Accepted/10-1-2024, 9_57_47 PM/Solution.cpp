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
        int countMin = 0;  //min # of unmatched '(', try to use * as ')' if possible. 
        for(auto ch: s) {
            if(ch=='(') {
                countMax++;
                countMin++;
            } else if(ch==')') {
                countMax--;
                countMin--;                
            } else {
                countMax++;
                countMin--;      
            }
            if(countMax < 0 )
                return false;  
            if(countMin < 0 ) 
                countMin = 0;    //countMin += 2. if * can not be empty.        
        }
        return  countMin == 0;
    }
};