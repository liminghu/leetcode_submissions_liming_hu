// https://leetcode.com/problems/valid-palindrome-ii

//Given a string s, return true if the s can be palindrome after deleting at most one character from it.
class Solution {
public:
    bool validPalindrome(string s) {
        //1 <= s.length <= 105
        //s consists of lowercase English letters.
        if(isPalindrome(s))
            return true;
        int sz = s.length();
        string new_s = "";
        for(int i=0; i<sz; i++) {
            //delete s[i];
            new_s = s.substr(0, i) + s.substr(i+1, sz-i-1);
            //string new_s1 = s.substr(0, i);
            //string new_s2 = s.substr(i+1, sz-i-1);
            //new_s = new_s1 + new_s2;
            if(isPalindrome(new_s))
                return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int sz = s.length();
        if(sz <=1)
            return true;

        int i=0;
        int j = sz-1;
        while(i<j) {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};