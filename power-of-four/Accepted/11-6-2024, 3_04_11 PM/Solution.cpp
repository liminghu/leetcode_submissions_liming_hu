// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        while(n % 4 == 0)
            n = n>>2;
        return n==1;
    }
};