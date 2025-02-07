// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) { //Kadane's Algorithm
        int n = nums.size();
        int max_sum = nums[0];
        int cur_sum = 0;
        for(size_t i=0; i<n; i++) {
            cur_sum = max(cur_sum, 0) + nums[i];
            max_sum = max(max_sum, cur_sum);            
        }
        return max_sum;
    }
};