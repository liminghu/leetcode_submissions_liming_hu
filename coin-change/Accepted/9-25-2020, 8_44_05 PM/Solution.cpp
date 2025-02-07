// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int ans=INT_MAX;
		sort(coins.rbegin(), coins.rend()); //sort coins in descending order.
		
		coinChange(coins, 0, amount, 0, ans);
		
		return ans == INT_MAX? -1 : ans;
		
		}
private:
	void coinChange(vector<int>& coins, int s, int amount, int count, int& ans) {
		const int coin = coins[s];
		
		//last element
		if(s == coins.size() - 1 ) {
			if(amount % coin == 0)
				ans = min(ans, count + amount / coin);
		} else {
			for (int k = amount / coin; k >=0 && count + k < ans; k--)
				coinChange(coins, s+1, amount-k*coin, count+k, ans);
		}
	}	
};
	
	