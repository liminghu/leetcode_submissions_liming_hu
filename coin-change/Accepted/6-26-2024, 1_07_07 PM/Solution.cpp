// https://leetcode.com/problems/coin-change

class Solution { //https://leetcode.com/problems/coin-change/solutions/778548/c-dp-solution-explained-100-time-100-space/
public:
/*
You are given an integer array coins representing coins of different denominations and 
an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of 
money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/
    int coinChange(vector<int>& coins, int amount) { //1 <= coins.length <= 12
                                                    //1 <= coins[i] <= 231 - 1
                                                    //0 <= amount <= 104
        int sz = coins.size();
        //dp[j]：凑足总额为j所需钱币的最少个数为dp[j]
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        //凑足总额为j - coins[i]的最少个数为dp[j - coins[i]]，那么只需要加上一个钱币coins[i]即dp[j - coins[i]] + 1就是dp[j]（考虑coins[i]）
        //所以dp[j] 要取所有 dp[j - coins[i]] + 1 中最小的。
        //递推公式：dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        for(int i=0; i<sz; i++) {
            for( int j = coins[i]; j <= amount; j++ ) {
                dp[j] = min( dp[j], dp[ j-coins[i] ] + 1 );
            }
        }

        if(dp[amount] == INT_MAX )
            return -1;
        else
            return dp[amount];
    }
};