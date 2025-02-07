// https://leetcode.com/problems/evaluate-reverse-polish-notation

/*
Postfix notation ("Reverse Polish")
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_st;
        int n = tokens.size();
        for(int i=0; i<n; i++) {
            if( tokens[i]=="+" || tokens[i]=="-"|| tokens[i]=="*" || tokens[i]=="/" ) {
                int num2 = num_st.top();
                num_st.pop();
                int num1 = num_st.top();
                num_st.pop();
                if(tokens[i] == "+") { 
                    num_st.push(  num1 + num2  );
                } else if ( tokens[i] == "-") {
                    num_st.push(  num1 - num2  );
                } else if ( tokens[i] == "*") {
                    num_st.push(  num1 * num2  );
                } else if ( tokens[i] == "/") {
                    num_st.push(  num1 / num2  );
                } else  {
                    cout << "sth wrong!" << endl;
                };
            } else 
                num_st.push( stoi(tokens[i]) );
        };
        return num_st.top();
    }
};