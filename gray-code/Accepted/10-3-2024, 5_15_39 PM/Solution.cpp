// https://leetcode.com/problems/gray-code

/*
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Constraints:
1 <= n <= 16
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0; i< (1<<n); i++) { //2^n
            res.push_back( i ^ (i/2) );
        }
        return res;
    }
};