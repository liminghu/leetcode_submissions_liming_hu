// https://leetcode.com/problems/longest-repeating-substring

/*
Given a string s, return the length of the longest repeating substrings. If no repeating substring exists, return 0.
1 <= s.length <= 2000
s consists of lowercase English letters.
*/
class Solution {
    uint64_t BASE = 26;
    uint64_t MOD = 1e9+123;
public:
    int longestRepeatingSubstring(string s) {
        int lo = 1;
        int hi = s.length() -1;
        int mid = 0;
        while( lo < hi ) {
            mid = ( lo + hi + 1 ) >> 1;
            if( hasRepeated(s, mid) )
                lo = mid;
            else
                hi = mid -1;
        }
        return hasRepeated(s,lo)? lo: lo - 1;

/*        int sz = s.length();
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
        return l-1;*/
    }
    bool hasRepeated( string s, int len) {
        unordered_set<long long> Set;
        long long  hash = 0l;
        long long pow = 1;
        for(int i=0; i<len; i++) { //build the initial rolling hash
            hash = (hash* BASE + s[i] - 'a') % MOD;
            pow = (pow*BASE) % MOD; 
        }
        Set.insert(hash);
        for(int i=len; i<s.length(); i++) {
            hash = (hash*BASE - (s[i-len] - 'a')*pow + MOD + s[i]-'a' ) % MOD;
            if(Set.find(hash)!= Set.end()) {
                Set.insert(hash);
                return true;
            }
        }
        return false;

    }
 /*   bool foundRepeatedSub(string s, int len) {
        unordered_set<string> seen;
        for(int i=0; i<=s.length() - len; i++) {
            string sub = s.substr(i, len);
            if(seen.find(sub) != seen.end() ) {
                return true;
            }
            seen.insert(sub);
        }
        return false;
    }*/
};