// https://leetcode.com/problems/count-good-numbers

class Solution {
long long M = 1e9+7;
public:
    int countGoodNumbers(long long n) {//A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
        //Given an integer n, return the total number of good digit strings of length n
        //A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

        long long count4 = n/2;
        long long count5 = n - count4;
        long long ans = (( power(4ll, count4) % M  * power(5ll, count5) % M ) % M);
        return int(ans);
    }

    long long power(long long x, long long y) {
        long long res = 1;
         x = x % M;
         if(x==0ll)
            return 0ll;
        if( y ==1)
            return x;
        while(y>0) {
            if(y&1) //y is odd.
                res = (res*x) % M;
            x = (x * x ) % M;  
            y = y >> 1;
        }
        return res;
    }
};