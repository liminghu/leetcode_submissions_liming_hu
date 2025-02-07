// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1;
        int prev = 0;
        int res = 0;
        for(int i=1; i<s.size(); i++) {
            if(s[i]==s[i-1])
                cur++;
            else {
                res += min(cur, prev);
                prev = cur;
                cur = 1;
            }
        }
        return res+min(cur, prev);
    }
};