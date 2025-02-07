// https://leetcode.com/problems/word-pattern-ii

class Solution {
private:
    unordered_map<char, string> mp;
    unordered_map<string, char> re_mp;
public:
    bool wordPatternMatch(string pattern, string s) {
        //A string s matches a pattern if there is some bijective mapping of single characters to non-empty strings such that if each character in pattern is replaced by the string it maps to, then the resulting string is s
        return dfs(pattern, 0, s, 0);
    }
    bool dfs(string pattern, int pp, string s, int ps) {
        if(pp == pattern.size()) 
            return ps == s.size();
        if(mp.find(pattern[pp]) != mp.end() ) {
            string match = mp[pattern[pp]];
            if( ps + match.size() > s.size() )
                return false;
            if( s.substr(ps, match.size() ) == match ) {
                return dfs(pattern, pp+1, s, ps+match.size());
            } else
                return false;
        } else {
            for(int j=ps; j<s.size(); j++) {
                string match = s.substr(ps, j-ps+1);
                if(re_mp.find(match) != re_mp.end())
                    return false;  //been match by other char before.
                mp[pattern[pp]] = match;
                re_mp[match] = pattern[pp];
                if(dfs(pattern, pp+1, s, ps+match.size()))
                    return true;
                //backtracking
                mp.erase(pattern[pp]);
                re_mp.erase(match);
            }
        }
        
        return false;
    }
};