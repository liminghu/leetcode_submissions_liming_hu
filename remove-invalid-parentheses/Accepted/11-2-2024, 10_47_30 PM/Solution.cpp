// https://leetcode.com/problems/remove-invalid-parentheses

class Solution {
vector<string> rets;
int maxLen;
public:
    vector<string> removeInvalidParentheses(string s) {
        int count = 0;
        int remove = 0;
        for(auto ch: s) {
            if(ch=='(')
                count++;
            else if(ch==')')
                count--;
            if(count<0) {
                remove++;
                count = 0;
            };
        } 
        remove += count;
        maxLen = s.length() - remove;
        string curStr = "";
        dfs(s, 0, curStr, 0);
        return rets;
    }
    void dfs(string& s, int i, string curStr, int count) { //count: unmatched left parentheses.
        if(count < 0)
            return;
        if(curStr.size() > maxLen)
            return;
        if( i == s.length() ) {
            if(count == 0 && curStr.size() == maxLen)
                rets.push_back(curStr);
            return;
        }
        if(s[i] != '(' && s[i] != ')')
            dfs(s, i+1, curStr+s.substr(i,1), count);
        else {
            dfs(s, i+1, curStr+s.substr(i,1), count + ((s[i]=='(')? 1 : -1) );
            if(curStr.empty() || s[i] != curStr.back())
                dfs(s, i+1, curStr, count); //s[i] is not selected.
        }
        return;
    }
};