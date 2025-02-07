// https://leetcode.com/problems/permutation-in-string

/*Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
 
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if( n < m )
            return false;
        
        vector<char> s1_freq(26,0);
        vector<char> s2_count(26,0);
        for(int i=0; i<m; i++) {
            s1_freq[ s1[i]-'a']++;
            s2_count[ s2[i]-'a']++;
        }
        if(s1_freq == s2_count)
            return true;
        for(int i=m; i<n; i++) {
            s2_count[ s2[i]-'a']++;
            s2_count[ s2[i-m]-'a']--;
            if(s2_count == s1_freq)
                return true;
        }
        return false;
        
    }
};