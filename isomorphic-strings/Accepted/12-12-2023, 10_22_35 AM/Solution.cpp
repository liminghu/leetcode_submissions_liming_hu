// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> src_map, dst_map;
        if(s.length()!=t.length())
             return false;
        for(size_t i=0; i<s.size(); i++) {
            if(src_map.count(s[i])==0 && dst_map.count(t[i])==0) {
                src_map[s[i]] = t[i];
                dst_map[t[i]] = s[i];
            } else if (src_map[s[i]]!=t[i] || dst_map[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};