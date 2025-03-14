// https://leetcode.com/problems/ugly-number-iii

/*
An ugly number is a positive integer that is divisible by a, b, or c.
Given four integers n, a, b, and c, return the nth ugly number.

Example 1:
Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Example 2:
Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.

Example 3:
Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
 
Constraints:
1 <= n, a, b, c <= 109
1 <= a * b * c <= 1018
It is guaranteed that the result will be in range [1, 2 * 109].
*/
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lo = 1;
        long long hi = 2*(int)1e9;
        long long ab = lcm(long(a),long(b));
        long long bc = lcm(long(b),long(c));
        long long ac = lcm(long(a),long(c));
        long long abc = lcm(long(a),long(bc));
        while( lo < hi ) {
            long long mid = lo + (hi-lo)/2;
            long long cnt = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;
            if( cnt >= n) 
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;   

    }
    long long gcd(long long int a, long long int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    // Function to return LCM of two numbers 
    long long lcm(long long a, long long b) {
        return (a*b) / gcd(a, b);
    }
};

