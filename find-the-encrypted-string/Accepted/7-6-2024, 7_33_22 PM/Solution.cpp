// https://leetcode.com/problems/find-the-encrypted-string

class Solution {
public:
    string getEncryptedString(string s, int k) {
        //For each character c in s, replace c with the kth character after c in the string (in a cyclic manner).
        int sz = s.length();
        string ans = "";
        for(int i=0; i<sz; i++) {
            ans += s[(i+k)%sz];
        }
        return ans;
        
    }
};