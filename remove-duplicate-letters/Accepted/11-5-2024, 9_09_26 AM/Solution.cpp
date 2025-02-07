// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> count(26, 0);
        vector<bool> used(26, false);
        for(int i=0; i<s.length(); i++) 
            count[s[i]-'a']++;
        string res = "";
        for(int i=0; i<s.length(); i++) {
            count[s[i]-'a']--;
            if( used[s[i]-'a'] || (!st.empty() && st.top() == s[i]))
                continue;
            while(!st.empty() && st.top() > s[i] && count[st.top()-'a'] > 0) { //stack top char must have duplicates, and greater than current char.
                used[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            used[s[i]-'a'] = true;
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};