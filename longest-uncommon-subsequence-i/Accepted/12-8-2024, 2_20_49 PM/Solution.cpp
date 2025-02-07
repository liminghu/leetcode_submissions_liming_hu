// https://leetcode.com/problems/longest-uncommon-subsequence-i

class Solution {
public:
    int findLUSlength(string a, string b) {
        int m = a.length();
        int n = b.length();
        if(a==b)
            return -1;
        return max(m, n);
    }
};