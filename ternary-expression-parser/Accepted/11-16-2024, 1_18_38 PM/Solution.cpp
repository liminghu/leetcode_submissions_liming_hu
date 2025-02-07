// https://leetcode.com/problems/ternary-expression-parser

class Solution {
public:
    string parseTernary(string expression) {
        //only contains digits, '?', ':', 'T', and 'F' where 'T' is true and 'F' is false. All the numbers in the expression are one-digit numbers (i.e., in the range [0, 9]).
        stack<char> st;
        int i= expression.length() - 1;
        while(i>=0) { //right to left
            char curr = expression[i];
            if(curr>='0' && curr<='9' || curr=='T' || curr == 'F')
                st.push(curr);
            else if(curr=='?') {
                char onTrue = st.top();
                st.pop();
                char onFalse = st.top();
                st.pop();
                st.push(expression[i-1]=='T'? onTrue:onFalse);
                i--;
            }
            i--;
        }
        string res;
        res += st.top();
        return res;
    }
};