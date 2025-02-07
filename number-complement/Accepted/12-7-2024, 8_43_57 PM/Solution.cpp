// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int todo = num;
        int bit = 1;
        while(todo) {
            num = num ^ bit;
            bit = bit<<1;
            todo = todo>>1;
        };
        return num;
    }
};