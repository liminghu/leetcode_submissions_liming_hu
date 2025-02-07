// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    int numberOfSteps(int num) {
        if (num < 0) 
            return -1;
        int steps = 0;
        while( num != 0) {
            if (num%2 == 0) {
                num = num/2;
                steps++;
            } else {
                num = num -1;
                steps++;
            }
        };
        return steps;
    }
};