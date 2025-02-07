// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        //dp[i] => s[1:i]里以s[i]结尾的、最长的递增子序列的长度
        vector<int> dp(sz,0);
        dp[0] = 1;

        int ret = INT_MIN;
        for(int i=1; i<sz; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j]< nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
                else
                    dp[i] = max(dp[i], dp[j]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};