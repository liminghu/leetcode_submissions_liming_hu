// https://leetcode.com/problems/number-of-1-bits

/*Write a function that takes the binary representation of a positive integer and returns the number of 
set bits
 it has (also known as the Hamming weight).
 1 <= n <= 231 - 1
 */
class Solution {
public:
    int hammingWeight(int n) {
        int ret = 0;
        for(int i=0; i<32; i++)
            ret += (n>>i)&1;
        return ret;
    }
};