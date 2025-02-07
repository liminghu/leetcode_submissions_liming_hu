// https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference

class Solution {
public:
    int longestSubsequence(vector<int>& nums) { //1 <= nums[i] <= 300
        int res = 0;
        int n = nums.size();
        vector<vector<int>> dp(301, vector<int>(301, 0));
        for(int i=n-1; i>=0; i--) {
            for(int nextNum=1; nextNum<=300; nextNum++) {
                int diff = abs(nums[i]-nextNum);
                dp[nums[i]][diff] = max(dp[nums[i]][diff], dp[nextNum][diff]+1);
            }
            for(int diff=1; diff<300; diff++) {
                dp[nums[i]][diff] = max(dp[nums[i]][diff], dp[nums[i]][diff-1]);
                res = max(res, dp[nums[i]][diff]);
            }
        }
        return res;
    }
};