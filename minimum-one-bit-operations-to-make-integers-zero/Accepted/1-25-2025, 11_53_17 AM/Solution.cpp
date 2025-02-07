// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero

class Solution {
public:
    int minimumOneBitOperations(int n) {//0 <= n <= 10^9
        if(n<=1)
            return n;
        int bit = 0;
        while((1<<bit)<=n)
            bit++;
        return ( (1<<bit)-1 ) - minimumOneBitOperations( n - (1<<(bit-1)));
        
    }
};