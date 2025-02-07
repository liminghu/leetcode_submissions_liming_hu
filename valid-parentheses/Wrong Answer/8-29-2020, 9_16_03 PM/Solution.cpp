// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
		if(s.length()%2!=0) return false;
		stack<char> opennningBrackets;
		for(int i=0; i<s.length(); i++) {
			if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
				opennningBrackets.push(s[i]);
			}else if (s[i]==')' && !opennningBrackets.empty() && opennningBrackets.top()=='(') {
				opennningBrackets.pop();
			}else if (s[i]==']' && !opennningBrackets.empty() && opennningBrackets.top()=='[') {
				opennningBrackets.pop();
			}else if (s[i]=='}' && !opennningBrackets.empty() && opennningBrackets.top()=='{') {
				opennningBrackets.pop();
			}
		}
		return opennningBrackets.empty();
    }
};