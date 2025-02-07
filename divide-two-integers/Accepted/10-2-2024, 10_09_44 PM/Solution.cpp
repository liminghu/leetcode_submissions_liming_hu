// https://leetcode.com/problems/divide-two-integers

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be 
truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: 
[−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the 
quotient is strictly less than -231, then return -231.
-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) && (divisor < 0) || (dividend >= 0) && (divisor >= 0)? 1: -1;
        long ldividend = abs( (long)dividend );
        long ldivisor = abs( (long)divisor );

        long res = 0;
        while(ldivisor <= ldividend ) {//can be divided.
            long temp = ldivisor;
            long mul = 1;
            while( (temp<<1) <= ldividend ) { //temp can become bigger.
                temp <<= 1;
                mul  <<= 1;
            };

            res += mul;
            ldividend -= temp;
        };

        res *= sign;
        if(res >= INT_MAX )
            return INT_MAX;
        else
            return (int)res;
    }
};