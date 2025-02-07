// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ret = 0;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(count < 0) { 
                ret++;
                count = 0;
            }
            if(s[i] == '(')
                count++;
            else if(s[i]==')')
                count--;
        }
        if(count < 0) { 
                ret++;
                count = 0;
        }
        return ret+count;
    }
};