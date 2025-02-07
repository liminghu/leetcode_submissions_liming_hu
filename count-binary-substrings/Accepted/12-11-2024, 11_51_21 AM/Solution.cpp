// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1;//count the number of 1 or 0 grouped consecutively.
        int prev = 0;
        int res = 0;
        for(int i=1; i<s.size(); i++) {
            if(s[i]==s[i-1])
                cur++;
            else {
                // for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring will be the minimum number of 0 and 1.
                //For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111")
                res += min(cur, prev);
                prev = cur;
                cur = 1;
            }
        }
        return res+min(cur, prev);
    }
};