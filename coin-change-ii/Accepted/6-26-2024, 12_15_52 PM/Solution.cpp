// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
*/
    int change(int amount, vector<int>& coins) { //1 <= coins.length <= 300
                                                    //1 <= coins[i] <= 5000
                                                    //All the values of coins are unique.
                                                    //0 <= amount <= 5000
        if(amount == 0)
            return 1;
        
        sort(coins.begin(), coins.end());
        int sz = coins.size();

       // if(sz == 1 && amount == coins[0])
       //     return 1;
       // else
       //     return 0;

        vector<int> dp(amount+1, 0); //dp[j]：凑成总金额j的货币组合数为dp[j]

        //dp[j] 就是所有的dp[j - coins[i]]（考虑coins[i]的情况）相加。
        dp[0] = 1;
        for(int i=0; i<sz; i++) { //for all the coins.
            for(int j=coins[i]; j<=amount; j++) { //traverse the backpack capability.
                dp[j] += dp[j-coins[i]]; 
            }
        };

        return dp[amount];
    }
};