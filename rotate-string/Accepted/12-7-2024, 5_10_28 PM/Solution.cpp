// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        string dd = s+s;
        return dd.find(goal) < dd.length();
    }
};