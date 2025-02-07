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
        int start = s.find(first);
        if(first.length()>0 && start!=string::npos)
            start += first.length();
        else
            start = 0;
        secondMatch = second.length()>0 && s.find(second, start)!=string::npos || second.length()==0;
        cout << "second match: "<< secondMatch << endl;
        return firstMatch && secondMatch;
    }
};