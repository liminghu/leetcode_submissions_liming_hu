// https://leetcode.com/problems/factorial-trailing-zeroes

/*
Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
*/
class Solution {
public:
    int trailingZeroes(int n) {
        // pairs of (2, 5)
        // number of 10: 1 *2    1*5
        // 1~24: n/5 5s.
        // number of 25: 5*5:      25/5   + 5/5
        int num5 = 0;
        while(n != 0 ) {
            n = n/5;
            num5 += n;
        };
        return num5;        

    }
};