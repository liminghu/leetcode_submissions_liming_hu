// https://leetcode.com/problems/delete-characters-to-make-fancy-string

class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() < 3)
            return s;
        int j=2;
        for(int i=2; i<s.length(); i++) {
            if(s[i]!=s[j-1] || s[i] != s[j-2]) {
                s[j] = s[i];
                j++;
            }
        }
        s.resize(j);
        return s;
    }
};