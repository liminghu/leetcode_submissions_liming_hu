// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = INT_MIN;
        dp[2] = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int k= nums[i] % 3;
            auto dp_temp = dp;
            for(int j=0; j<3; j++) {
                dp[j] = max(dp_temp[j], dp_temp[(j-k+3)%3]+nums[i]);
            }
        }
        return dp[0];
    }
};