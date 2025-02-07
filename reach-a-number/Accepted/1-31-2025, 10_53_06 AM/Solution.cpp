// https://leetcode.com/problems/reach-a-number

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int steps = 0;
        while(target > 0) {
            steps++;
            target -= steps;
        };
        return target%2==0? steps: steps+1+steps%2; 
    }
};