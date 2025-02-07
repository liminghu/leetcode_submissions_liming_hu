// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        K = min(K, n/2+1);
        vector<vector<int>> sold(n, vector<int>(K+1,0)); //finished k transactions without stock.
        vector<vector<int>> hold(n, vector<int>(K+1,0)); //finsihed k transaction with stock hold.

        for(int i=0; i<n; i++) {
            for(int k=0; k<=K; k++) {
                if(i==0 && k==0) {
                    sold[0][0] = 0; //finsihed 0 transactions, no hold.
                    hold[0][0] = -prices[0]; //finished 0 transactions. must hold 
                } else if(i==0) { // k>=1
                    sold[0][k] = INT_MIN/2; //finsihed k transactions, no hold.
                    hold[0][k] = INT_MIN/2; //finished k transactions. must hold 
                } else if(k==0) { //i>0. 0 transactions.
                    sold[i][0] = sold[i-1][0]; ////finsihed 0 transactions, no hold.
                    hold[i][0] = max( hold[i-1][0], sold[i-1][0] - prices[i] );
                } else {
                    sold[i][k] = max( sold[i-1][k], hold[i-1][k-1] + prices[i] );
                    hold[i][k] = max( hold[i-1][k], sold[i-1][k]   - prices[i] ); //do nothing, buy
                }
            }
        }
        return *max_element(sold[n-1].begin(), sold[n-1].end());
    }
};