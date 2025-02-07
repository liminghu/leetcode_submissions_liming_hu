// https://leetcode.com/problems/sum-of-square-numbers

//Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
class Solution {
public:
    bool judgeSquareSum(int c) {
        //0 <= c <= 231 - 1
        int sz = sqrt(c);
        for(int a=0;a<=sz; a++) {
            int b = sqrt(c - a*a);
            if(b*b+a*a == c)
                return true;
        }

        return false;
    }
};