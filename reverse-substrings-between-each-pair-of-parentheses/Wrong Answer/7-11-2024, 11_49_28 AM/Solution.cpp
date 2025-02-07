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
        queue<int> qu;
        string ans = s;
        for(int i=0; i<sz; i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
                qu.push(i);
        };

        if(st.size() != qu.size()) {
            return "";
        }

        while(!qu.empty()) {
            int close_i = qu.front();
            qu.pop();

            int open_i = st.top();
            st.pop();

            //reverse open_i+1, close_i-1;
            int start = open_i+1;
            int end = close_i -1;
            while(start<end) {
                swap(ans[start], ans[end]);
                start++;
                end--;
            };
        }

        string final_ans = "";
        for(int i=0; i<ans.length(); i++) {
            if(ans[i] == '(' || ans[i] == ')')
                continue;
            final_ans += ans[i];
        };

        return final_ans;
        
    }
};