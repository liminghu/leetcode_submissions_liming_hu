// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome

class Solution {
public:
    int minMovesToMakePalindrome(string s) {//s consisting only of lowercase English letters.
        int res = 0;
        /*Considering the first and the last char in final palindrome.
        If they are neither the first nor the last char in the initial string,
        you must waste some steps:
        Assume start with "...a....a.."
        ".a.......a." can be ealier completed thand "a.........a".
        Then compare the situation "a....b..a...b"
        It takes same number of steps to "ab.........ba" and "ba.........ab".
        So we can actually greedy move the characters to match string prefix.
        */
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