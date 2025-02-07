// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps;
        steps.push_back(1);
        steps.push_back(1);
        for (int i=2; i<=n; i++) {
            steps.push_back(steps[i-2]+steps[i-1]);
        };
        return steps[n];
    }
};