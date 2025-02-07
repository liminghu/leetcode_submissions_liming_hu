// https://leetcode.com/problems/minimum-string-length-after-removing-substrings

class Solution {
public:
    int minLength(string s) {
        //"AB" or "CD"
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(st.empty()) {
                st.push(c);
                continue;
            };
            if(c=='B' && st.top() == 'A')
                st.pop();
            else if(c=='D' && st.top() == 'C')
                st.pop();
            else
                st.push(c);
        };
        return st.size();
    }
};