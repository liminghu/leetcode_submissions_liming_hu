// https://leetcode.com/problems/scramble-string

/*
We can scramble a string s to get a string t using the following algorithm:
If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.
 */
class Solution {
    unordered_map<string, int> mp;
public:
    bool isScramble(string s1, string s2) {
        if( mp.find( s1+"_"+s2 )!=mp.end() )
            return mp[s1+"_"+s2];

        int n = s1.length();
        if(s1 == s2) {
            mp[s1+"_"+s2] = 1;
            return true;
        }
        if( counter(s1) != counter(s2) ) {
            mp[s1+"_"+s2] = 0;
            return false;
        }
        for(int k=1; k<n; k++) {
            //s1 divide into s1_1 s1_2
            string s1_1 = s1.substr(0, k);
            string s1_2 = s1.substr(k, n-k);

            string s2_1 = s2.substr(0, k);
            string s2_2 = s2.substr(k, n-k);
            if( isScramble(s1_1, s2_1) && isScramble(s1_2, s2_2) ) {
                mp[s1+"_" + s2] = true;
                return true;
            }
            s2_1 = s2.substr(0, n-k);
            s2_2 = s2.substr(n-k, k);
            if( isScramble(s1_1, s2_2) && isScramble(s1_2, s2_1) ) {
                mp[s1+"_" + s2] = true;
                return true;
            }
        };
        mp[s1+"_" + s2] = 0;
        return false;
    }

    vector<int> counter(string s) {
        vector<int> ans(26, 0);
        for(int i=0; i<s.length(); i++) {
            ans[s[i]-'a']++;
        };
        return ans;
    }
};