// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        //-x = ~x+1;
        //return ( n & (-n) ) == n;
        return ( n & (n-1) )  == 0;
    }
};