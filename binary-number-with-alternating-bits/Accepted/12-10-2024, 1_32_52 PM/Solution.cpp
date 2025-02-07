// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n<=1)
            return true;
        int cur_bit = (n & 1);
        n = n>>1;
        while(n>0) {
            if( (n & 1) == cur_bit)
                return false;    
            n = n>>1;
            cur_bit = 1-cur_bit;
        }
        return true;
    }
};