// https://leetcode.com/problems/longest-valid-parentheses

/*Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring.
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ret = 0;
        if( s.length()==0 )
            return 0;
        for(int i=0; i<s.length(); i++) {
            if( s[i] == '(' )
                st.push(i);
            else { // s[i] == ')'
                if( !st.empty() && s[st.top()] == '(' ) {
                    st.pop();
                    int t = st.empty()? -1: st.top();
                    ret = max( ret,  i - t );
                } else //top: empty, or ')'
                    st.push(i); //it will become the new wall.
            }
        }
        return ret;
    }
};