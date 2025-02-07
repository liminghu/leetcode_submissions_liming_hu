// https://leetcode.com/problems/substring-matching-pattern

class Solution {
public:
    bool hasMatch(string s, string p) {
        int star_pos = p.find('*');
        string first="";
        if(star_pos != 0)
            first = p.substr(0, star_pos);
        cout << "first: "<< first << endl;
        string second = "";
        if(star_pos != s.length()-1)
            second=p.substr(star_pos+1);
        cout << "second: "<< second << endl;        
        bool firstMatch = first.length()>0 && s.find(first)!=string::npos || first.length()==0;
        bool secondMatch = false;
        int start = 0;
        if(first.length()>0 && s.find(first)!=string::npos)
            start = s.find(first);
        secondMatch = second.length()>0 && s.find(second, start)!=string::npos || second.length()==0;
        return firstMatch && secondMatch;
    }
};