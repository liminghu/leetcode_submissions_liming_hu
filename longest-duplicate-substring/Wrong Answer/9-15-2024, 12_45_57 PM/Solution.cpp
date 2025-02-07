// https://leetcode.com/problems/longest-duplicate-substring

/*
Given a string s, consider all duplicated substrings: (contiguous) substrings
 of s that occur 2 or more times. The occurrences may overlap.
Return any duplicated substring that has the longest possible length. If s 
does not have a duplicated substring, the answer is "".
Constraints:
2 <= s.length <= 3 * 104
s consists of lowercase English letters.
*/
typedef uint64_t ULL; //unsigned integer type with width of exactly 64 bits.

class Solution {
    unordered_map<int, int> len2start;
public:
    string longestDupSubstring(string s) {
        int l = 1;
        int r = s.length()-1;
        while(l < r) {
            int m = r - (r-l)/2;
            if( found(s, m) )
                l = m;
            else
                r = m-1;
        }
        if( found(s, l) )
            return s.substr( len2start[l], l);
        else
            return "";
    }
    bool found(string s, int len) {
        unordered_set<ULL> Set;
        ULL base = 31;
        ULL hash = 0;

        ULL pow_base_len = 1;
        for(int i=0; i<len; i++) 
            pow_base_len *= base; 
        
        for(int i=0; i<s.length(); i++) {
            hash = hash * base + s[i] - 'a';
            if( i >= len ) 
               hash = hash - pow_base_len * (s[i-len] - 'a');  
            
            if( i >= len - 1) {
                if( Set.find(hash) != Set.end() ) {
                    len2start[len] = i - len + 1;
                    return true; 
                }
                Set.insert(hash);
            }
        }
        return false;
    }
};