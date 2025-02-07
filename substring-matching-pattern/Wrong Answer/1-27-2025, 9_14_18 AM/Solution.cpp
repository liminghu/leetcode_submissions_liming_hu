// https://leetcode.com/problems/substring-matching-pattern

class Solution {
public:
    bool hasMatch(string s, string p) {
        int star_pos = p.find('*');
        string first = p.substr(0, star_pos-1);
        string second = p.substr(star_pos+1);
        bool firstMatch = first.length()>0 && s.find(first)!=string::npos || first.length()==0;
        bool secondMatch = second.length()>0 && s.find(second)!=string::npos || second.length()==0;
        return firstMatch && secondMatch;
    }
};