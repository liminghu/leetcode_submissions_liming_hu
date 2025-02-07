// https://leetcode.com/problems/move-pieces-to-obtain-a-string

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        if(!sameSeq(start, target))
            return false;
        
        int i = 0;
        int j = 0;
        while(i<n && j<n) {
            while(start[i]=='_')
                i++;
            while(target[j]=='_')
                j++;
            if(start[i]!=target[j]) //relative order is not matched.
                return false;             
            if(start[i]=='R') {
                if(i>j)
                    return false;
            } else {//start[i]=='L'
                if(i<j)
                    return false;
            }
            i++;
            j++;
        }
        return true;
    }
    bool sameSeq(string s1, string s2) {
        string a;
        string b;
        for(char c: s1) {
            if(c!='_')
                a+=c;
        }
        for(char c: s2) {
            if(c!='_')
                b+=c;
        }        
        return a == b;
    }

};