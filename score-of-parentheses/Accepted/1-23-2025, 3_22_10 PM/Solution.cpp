// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {//2 <= s.length <= 50
        int cur = 0; //cur record the score at the current layer level.
        int n = s.length();
        stack<int> st;
        if(n==0)
            return 0;
        int i=0;
        while(i<n) {
            if(s[i]=='(') {
                /*If we meet '(',
                    we push the current score to stack,
                    enter the next inner layer level,
                    and reset cur = 0.*/
                st.push(cur);
                cur = 0;
            } else { //')'
            /*If we meet ')',
                the cur score will be doubled and will be at least 1.
                We exit the current layer level,
                and set cur += stack.pop() + cur
            */
                cur += st.top() + max(cur, 1);
                st.pop();
            }
            i++;
        }
        return cur;
    }
};