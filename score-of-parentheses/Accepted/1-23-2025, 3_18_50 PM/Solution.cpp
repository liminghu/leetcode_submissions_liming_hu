// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {//2 <= s.length <= 50
        int cur = 0;
        int n = s.length();
        stack<int> st;
        if(n==0)
            return 0;
        int i=0;
        while(i<n) {
            if(s[i]=='(') {
                st.push(cur);
                cur = 0;
            } else { //')'
                cur += st.top() + max(cur, 1);
                st.pop();
            }
            i++;
        }
        return cur;
    }
};