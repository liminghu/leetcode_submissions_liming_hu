// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> dict(26, 0);
        for(int i=0; i<s.size(); i++) {
            dict[s[i]-'a']++;
            dict[t[i]-'a']--;
        };
        int ans = 0;
        for(int i=0; i<26; i++) {
            ans += max(0, dict[i]);
        };
        return ans;
    }
};