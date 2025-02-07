// https://leetcode.com/problems/total-characters-in-string-after-transformations-i

class Solution {
    int M = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) { //1 <= t <= 105
        /*every character in s is replaced according to the following rules:
        If the character is 'z', replace it with the string "ab".
        Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
        */
        int res = 0;
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c-'a']++;
        while(t--) {
            int zCount = freq[25];
            freq[25] = 0;
            for(int i=24; i>=0; i--) {
                freq[i+1] = freq[i];
                freq[i] = 0;
            };
            if(zCount) {
                freq[0] = (freq[0]+zCount)%M;
                freq[1] = (freq[1]+zCount)%M;
            }
        }
        for(int i=0; i<26; i++)
            res = (res+freq[i])%M;
        return res;
    }
};