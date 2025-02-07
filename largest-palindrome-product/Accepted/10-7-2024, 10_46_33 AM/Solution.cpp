// https://leetcode.com/problems/largest-palindrome-product

/*Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. 
Since the answer can be very large, return it modulo 1337.

 

Example 1:

Input: n = 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
Example 2:

Input: n = 1
Output: 9
 

Constraints:

1 <= n <= 8
*/
class Solution {
public:
    int largestPalindrome(int n) { //1
        //croner case
        if(n==1)
            return 9; //3*3
        long long low = pow(10, n-1);  //1
        long long high = low * 10 - 1; //9
        for(long long i=high; i>=low; i--) { //10...1
            long long p = createPalindrome(i);
            for(int d = high; d>=sqrt(p); d--) {
                if( p%d == 0 && p/d >=low)
                    return p % 1337;
            }
        }
        return -1;
    }
    long long createPalindrome( long long i) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        return stoll(to_string(i) + s);
    }
};