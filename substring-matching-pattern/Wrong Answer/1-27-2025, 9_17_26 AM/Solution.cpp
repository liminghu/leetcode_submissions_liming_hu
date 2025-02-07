// https://leetcode.com/problems/substring-matching-pattern

class Solution {
public:
    bool hasMatch(string s, string p) {
        int star_pos = p.find('*');
        string first="";
        if(star_pos != 0)
            first = p.substr(0, star_pos-1);
        cout << "first: "<< first << endl;
        string second = p.substr(star_pos+1);
        cout << "second: "<< second << endl;        
        bool firstMatch = first.length()>0 && s.find(first)!=string::npos || first.length()==0;
        bool secondMatch = second.length()>0 && s.find(second)!=string::npos || second.length()==0;
        return firstMatch && secondMatch;
    }
};