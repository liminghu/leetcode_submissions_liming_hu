// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int n = s.length();
        res.push_back(s[0]);
        for(int i=1; i<n; i++) {
            if(!res.empty() && s[i]==res.back())
                res.pop_back();
            else
                res.push_back(s[i]);
        }
        return res;
    }
};