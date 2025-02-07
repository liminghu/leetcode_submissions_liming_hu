// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for(auto coin : coins) {
			for(int i = amount - coin; i>=0; i--) {
				if(dp[i] != INT_MAX)
					for( int k =1; k*coin +i <= amount; k++) 
						dp[i+k*coin] = min(dp[i+k*coin], dp[i] + k );
			}
		}
		return dp[amount] == INT_MAX? -1 : dp[amount];
	}
};