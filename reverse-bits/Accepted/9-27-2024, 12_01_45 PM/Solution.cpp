// https://leetcode.com/problems/reverse-bits

//Reverse bits of a given 32 bits unsigned integer.
//The input must be a binary string of length 32
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits(32,0);
        for(int i=0; i<16; i++) {
            bits[31-i] =  (n >> i)&1; //low
            bits[i] =  (n >> (31-i))&1; //high
        };

        uint32_t ret = 0;
        for(int i=0; i<32; i++)
            ret += bits[i] << i;
        return ret; 
    }
};