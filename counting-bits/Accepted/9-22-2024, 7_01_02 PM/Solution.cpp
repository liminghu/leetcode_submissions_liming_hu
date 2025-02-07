// https://leetcode.com/problems/counting-bits

/*
Given an integer n, return an array ans of length n + 1 such that for 
each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
0 <= n <= 105
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1, 0);
        //each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
        ret[0] = 0;
        for(int i=1; i<n+1; i++) {
            //i: 0..n
            //ret[i-1]    ret[i]
            if( (i-1) % 2 == 0 ) //i is odd.
                ret[i] = ret[i-1]+1;
            else // i is even.
                ret[i] = ret[i/2];
        }
        return ret;
    }
};