// https://leetcode.com/problems/sum-of-two-integers

/*Given two integers a and b, return the sum of the two integers without using the operators + and -.
-1000 <= a, b <= 1000
*/
class Solution {
public:
    int getSum(int a, int b) { //always the first one is bigger.
        int carry;
        while(b!=0) {
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};