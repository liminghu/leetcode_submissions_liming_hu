// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome

class Solution {
public:
    int minMovesToMakePalindrome(string s) {//s consisting only of lowercase English letters.
        int res = 0;
        while(s.size()) {
            int i = s.find(s.back());
            if(i==s.size()-1)
                res += i/2;
            else {
                res += i;
                s.erase(i, 1);
            }
            s.pop_back();
        }
        return res;
    }
};