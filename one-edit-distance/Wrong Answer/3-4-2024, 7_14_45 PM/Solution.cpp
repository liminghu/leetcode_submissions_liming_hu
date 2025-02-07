// https://leetcode.com/problems/one-edit-distance

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        if(abs(sLen-tLen)>1) return false;
        if (sLen > tLen)
            return isOneEditDistance(t, s);

        int diff = 0;
        
        int i=0, j=0;
        while(i<sLen && j < tLen) {
            if(toupper(s[i]) != toupper(s[j])) {
                if (diff == 1) return false;
                if(sLen > tLen) i++; //delete char in s
                else if (tLen > sLen) 
                    j++; //delete char at t.
                else {
                        //replace
                        i++; j++;                    
                }
                diff++;
                    
            } else { //the same
                i++; j++;    
            }
        }

        if(i<sLen || j < tLen) 
            diff++;

        return diff == 1;
    }
};