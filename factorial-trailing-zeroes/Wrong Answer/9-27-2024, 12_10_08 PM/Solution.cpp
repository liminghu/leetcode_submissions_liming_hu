// https://leetcode.com/problems/factorial-trailing-zeroes

/*
Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
*/
class Solution {
public:
    int trailingZeroes(int n) {
        // pairs of (2, 5)
        // number of 10.
        int num10 = 0;
        int num2 = 0;
        int num5 = 0;
        num10 = n / 10;
        num5 = n / 5 - num10;
        //num2 = n / 2;
        return num5 + num10;  
    }
};