// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        if((n & 3) == 0)
            return true;
        else
            return false;
    }
};