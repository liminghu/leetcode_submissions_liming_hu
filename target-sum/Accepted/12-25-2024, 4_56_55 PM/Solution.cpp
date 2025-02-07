// https://leetcode.com/problems/target-sum

/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols 
'+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 
and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
class Solution {
private:
    int dp[21][2001]; //1 <= nums.length <= 20, -1000 <= target <= 1000
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2*totalSum+1, 0)); //dp[index][sum] represents the number of ways to reach the sum sum using the first index numbers.
        dp[0][nums[0]+totalSum] = 1;
        dp[0][-nums[0]+totalSum] += 1;
        for(int i=1; i<nums.size(); i++) {
            for(int sum = -totalSum; sum<=totalSum; sum++) {
                if(dp[i-1][sum+totalSum] > 0) {
                    dp[i][sum+totalSum+nums[i]] += dp[i-1][sum+totalSum];
                    dp[i][sum+totalSum-nums[i]] += dp[i-1][sum+totalSum];
                }
            }
        }
        return abs(target)>totalSum? 0: dp[nums.size()-1][target+totalSum];
    }
    int findTargetSumWays1(vector<int>& nums, int target) {
        /*  1 <= nums.length <= 20
            0 <= nums[i] <= 1000
            0 <= sum(nums[i]) <= 1000
            -1000 <= target <= 1000
        */
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        const int offset = 1000;
        dp[0][0+offset] = 1;

        for(int i=1; i<=n; i++) 
            for(int s=-1000; s<=1000; s++) {
                if(s-nums[i] >=-1000 && s-nums[i] <= 1000)   //-1000 <= target <= 1000
                    dp[i][ s+offset ] += dp[i-1][ s-nums[i] + offset ];
                if(s+nums[i] >=-1000 && s+nums[i] <= 1000)
                    dp[i][ s+offset ] += dp[i-1][ s+nums[i] + offset];    
            }
        return dp[n][target+offset];
    }
};