// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> st;
        for(auto c:s) {
            if(st.find(c)!=st.end())
                st[c]++;
            else
                st[c] = 1;
        };
        
        for(auto c:t) {
            if(st.find(c)!=st.end()) {
                st[c]--;
                if(st[c]==0)
                   st.erase(c); 
            } else
                return c;
        };
        
        return t[t.size()-1];
    }
};