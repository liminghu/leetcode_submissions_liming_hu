// https://leetcode.com/problems/longest-repeating-substring

/*
Given a string s, return the length of the longest repeating substrings. If no repeating substring exists, return 0.
1 <= s.length <= 2000
s consists of lowercase English letters.
*/
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int sz = s.length();
        if( sz <= 1 )
            return 0;
        int l = 1; int r = sz-1;
        while( l <= r ) {
            int mid = (l+r)/2;
            if( foundRepeatedSub(s,mid) )
                l = mid + 1;
            else
                r = mid -1;
        }
        return l-1;
    }
    bool foundRepeatedSub(string s, int len) {
        unordered_set<string> seen;
        for(int i=0; i<=s.length() - len; i++) {
            string sub = s.substr(i, len);
            if(seen.find(sub) != seen.end() ) {
                return true;
            }
            seen.insert(sub);
        }
        return false;
    }
};