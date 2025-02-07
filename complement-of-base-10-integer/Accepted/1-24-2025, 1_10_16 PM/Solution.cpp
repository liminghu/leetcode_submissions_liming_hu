// https://leetcode.com/problems/complement-of-base-10-integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int todo = n;
        int bit = 1;
        while(todo!=0) {
            n = n ^ bit;
            bit = bit<<1;
            todo = todo>>1;
        };
        return n;
    }
};