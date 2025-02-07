// https://leetcode.com/problems/maximum-subarray

//Given an integer array nums, find the subarray with the largest sum, and return its sum.
/*Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/
 class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
 /*       int n = nums.size();
        int max_sum = nums[0];
        int cur_sum = 0;
        for(size_t i=0; i<n; i++) {
            cur_sum = max(cur_sum, 0) + nums[i];
            max_sum = max(max_sum, cur_sum);            
        }
        return max_sum;*/
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int ret = nums[0];
        for(int i=1; i<n; i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};