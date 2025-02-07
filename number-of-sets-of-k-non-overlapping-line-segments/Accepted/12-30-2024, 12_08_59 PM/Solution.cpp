// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments

class Solution {
    long M = 1e9+7;
public:
    int numberOfSets(int n, int K) {
        long dp[1001][1001];
        long sum[1001][1001];
        for(int i=0; i<n; i++) {
            dp[i][0] = 1;
            sum[i][0] = i+1;
        }
        /*当我们考察第i个点用来构造线段时，dp[i][k]依然可以写作dp[i][k] = sum {dp[j][k-1]} j=0,1,2...,i-1

        当我们考察第i个点不用来构造线段时，可以不必想解法1那样想得复杂。事实上，这种情况下就有dp[i][k] = dp[i-1][k].我们不需要根据空置长度来分类。

        因此，总的状态转移方程是：dp[i][k] = dp[i-1][k] + sum {dp[j][k-1]} j=0,1,2...,i-1. 我们只需要定义一个前缀和数组 sum[i][k]表示dp[0..i][k]的和。*/
        for(int i=1; i<n; i++) {
            for(int k=1; k<=min(i, K); k++) {
                dp[i][k] = dp[i-1][k] + sum[i-1][k-1];
                dp[i][k] %= M;
                sum[i][k] = sum[i-1][k]+dp[i][k];
                sum[i][k] %= M;
            };
        };
        return dp[n-1][K]%M;

    }
};