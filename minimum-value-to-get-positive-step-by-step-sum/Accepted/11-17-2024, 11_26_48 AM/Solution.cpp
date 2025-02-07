// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int min_sum = INT_MAX;
        int n=nums.size();
        for(int i= 0; i<n; i++) {
            sum += nums[i];
            min_sum = min(min_sum, sum);
        };

        return (1-min_sum <=0)? 1: 1-min_sum;
    }
};