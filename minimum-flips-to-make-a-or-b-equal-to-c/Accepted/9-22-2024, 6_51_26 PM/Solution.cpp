// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

/*
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
*/
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ret = 0;
        for(int i=0; i<32; i++) {
            int bit_a = (a >> i ) & 1;
            int bit_b = (b >> i ) & 1;
            int bit_c = (c >> i ) & 1;
            if((bit_a | bit_b) != bit_c) {
                if(bit_c == 0) {
                    ret += (bit_a + bit_b);
                } else { //1
                    ret += 1;
                }
            }
        }
        return ret;
        
    }
};