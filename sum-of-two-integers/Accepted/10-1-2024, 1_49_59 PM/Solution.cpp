// https://leetcode.com/problems/sum-of-two-integers

/*Given two integers a and b, return the sum of the two integers without using the operators + and -.
-1000 <= a, b <= 1000
*/
class Solution {
public:
    int getSum(int a, int b) { //always the first one is bigger.
        int c;
        while(b!=0) {
            c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};