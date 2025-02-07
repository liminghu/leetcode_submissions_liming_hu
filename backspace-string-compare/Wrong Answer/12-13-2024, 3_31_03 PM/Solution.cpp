// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        int j = 0;
        stack<char> st_s;
        stack<char> st_target;
        while(i<s.length()) {
            if(s[i] == '#' ) { 
                if(!st_s.empty())
                    st_s.pop();
                i++;
                continue;
            }; 
            st_s.push(s[i]);
            i++;
        }
        while(j<t.length()) {
            if(t[j] == '#' ) { 
                if(!st_target.empty())
                    st_target.pop();
                j++;
                continue;
            }; 
            st_target.push(t[j]);
            j++;
        }
        while(!st_s.empty() && !st_target.empty()) {
            if(st_s.top() == st_target.top()) {
                st_s.pop();
                st_target.pop();
            } else
                return false;
        }
        return true;
    }
};