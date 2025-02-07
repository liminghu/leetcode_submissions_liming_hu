// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses

/*You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.
 */
class Solution {
public:
    string reverseParentheses(string s) {
        /*1 <= s.length <= 2000
            s only contains lower case English characters and parentheses.
            It is guaranteed that all parentheses are balanced. 
        */
        int sz = s.length();
        if(sz <=1)
            return s;
        
        stack<int> st;
        for(int i=0; i<sz; i++) {
            if(s[i] == '(')
                st.push(i);
        };

        while(!st.empty()) {
            int open_i = st.top();
            st.pop();

             int close_i = 0;
            for(int i=open_i+1; i<sz; i++) {
                if(s[i] == ')') {
                    close_i = i;
                    s[i] = '('; 
                    break;
                }
            };
           
            //reverse open_i+1, close_i-1;
            int start = open_i+1;
            int end = close_i-1;
            while(start<end) {
                swap(s[start], s[end]);
                start++;
                end--;
            };
        }

        string final_ans = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == ')')
                continue;
            final_ans += s[i];
        };

        return final_ans;
        
    }
};