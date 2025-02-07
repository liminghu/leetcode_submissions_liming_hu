// https://leetcode.com/problems/n-th-tribonacci-number

/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.
0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        vector<int> trib(n+1, 0);
        trib[0] = 0;
        trib[1] = 1;
        trib[2] = 1;
        for(int i=3; i<=n; i++) {
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
        };
        return trib[n];
    }
};