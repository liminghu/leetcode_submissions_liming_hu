// https://leetcode.com/problems/bitwise-and-of-numbers-range

/*
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
0 <= left <= right <= 231 - 1
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while( right > left) {
            //When we do an AND bit operation between number and number - 1, the rightmost bit of one in the original number would be turned off (from one to zero).
            //Bitwise-AND of any two numbers will always produce a number less than or equal to the smaller number.
            right = right & (right - 1);
        };
        return right & left;
    }
};