// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0;
        int j = 0;
        stack<char> st_s;
        stack<char> st_t;
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
                if(!st_t.empty())
                    st_t.pop();
                j++;
                continue;
            }; 
            st_t.push(s[j]);
            j++;
        }
        while(!st_s.empty() && !st_t.empty()) {
            if(st_s.top() == st_t.top()) {
                st_s.pop();
                st_t.pop();
            } else
                return false;
        }
        return true;
    }
};