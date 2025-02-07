// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int left = 0;
        int i=0;
        int n = s.length();
        string ret;
        while(i<n) {
            if(s[i]=='(') {
                count++;
                left++;
            } else
                count--;
            if(count==0) {
                ret += s.substr(i+2-left*2, left*2-2);
                left = 0;
            };
            i++;
        }
        return ret;
    }
};