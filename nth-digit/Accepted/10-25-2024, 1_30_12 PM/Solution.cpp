// https://leetcode.com/problems/nth-digit

class Solution {
public:
    int findNthDigit(int n) {
        int start = 1; //1, 10, 100, 1000
        int digitNum = 1; //how many digits. start from 1.   1, 2, 3, 4
        long base = 9; // one digit: 9, two digits: 90, 3 digits: 900.
        while(n> digitNum * base) { //1*9, 2*90, 3*900 
            n -= digitNum * base;
            start *= 10;
            base *= 10;
            digitNum++;
        }

        start += (n-1) / digitNum;
        string s = to_string(start);
        char c = s[(n-1) % digitNum];
        return c-'0';
    }
};