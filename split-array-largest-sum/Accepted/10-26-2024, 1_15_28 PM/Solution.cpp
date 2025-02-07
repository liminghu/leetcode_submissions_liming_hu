// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int K) {
        int N = nums.size();
        auto dp = vector<vector<long>>(N+1, vector<long>(K+1, INT_MAX));
        nums.insert(nums.begin(), 0);
        dp[0][0] = 0;
        for(int i=1; i<=N; i++) {
            for(int k=1; k<=min(K, i); k++) {
                long sum = 0;
                for(int j=i; j>=k; j--) {
                    sum += nums[j];
                    dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], sum));
                }
            }
        }
        return dp[N][K];
    }
};