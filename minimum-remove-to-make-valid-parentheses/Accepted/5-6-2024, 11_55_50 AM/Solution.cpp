// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> stackIndex; //Using stack to store '(' index
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ')' && stackIndex.empty()) 
                continue;
            if(s[i] == '(') {
                stackIndex.push(ans.size());
            } else if(s[i] == ')' && !stackIndex.empty()) {
                stackIndex.pop();
            }

            ans+= s[i];
        }

        int numRemove = 0;
        while(!stackIndex.empty()) {
            int indexRemove = stackIndex.top();
            ans = ans.substr(0,indexRemove) + ans.substr(indexRemove+1);
            stackIndex.pop();
        }

        return ans;
    }
};