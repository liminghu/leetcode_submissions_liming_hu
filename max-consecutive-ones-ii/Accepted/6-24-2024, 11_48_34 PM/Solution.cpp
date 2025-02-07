// https://leetcode.com/problems/max-consecutive-ones-ii

class Solution {
public:
//Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
    int findMaxConsecutiveOnes(vector<int>& nums) { //1 <= nums.length <= 105; nums[i] is either 0 or 1.
        int sz = nums.size();
        vector<vector<int>> dp(sz, vector<int>(2, 0));
        int ret = INT_MIN;

        dp[0][0] = nums[0];
        dp[0][1] = 1;
        ret = max(ret, dp[0][0]);
        ret = max(ret, dp[0][1]);

        for(int i=1; i<sz; i++) {
            if(nums[i]==0) {
                dp[i][1] = dp[i-1][0] + 1;
                dp[i][0] = 0;
            } else { //1
                dp[i][1] = dp[i-1][1] + 1;
                dp[i][0] = dp[i-1][0] + 1;
            }

            ret = max(ret, dp[i][0]);
            ret = max(ret, dp[i][1]);

        }

        return ret;
    }
};