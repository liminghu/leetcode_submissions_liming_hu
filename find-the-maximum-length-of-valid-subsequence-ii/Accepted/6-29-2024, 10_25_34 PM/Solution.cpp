// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii

/*
You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:
(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
Return the length of the longest valid subsequence of nums.
*/
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<vector<int>> dp(sz, vector<int>(k, 0));

        int ans = 0;
        for(int i=0; i < sz; i++) {
            for(int j=0; j<i; j++) {
                int val = (nums[i]+nums[j]) % k;
                dp[i][val] = dp[j][val] +1;
                ans = max(ans, dp[i][val]);
            }
        }

        return ans+1;

        
    }
};