// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {//A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
        int count1 = 0;
        int flip = 0;
        for(auto c:s) {
            if(c == '1')
                count1++;
            else
                flip++;
            flip = min(flip, count1);
        }
        return flip;
    }
};