// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

/*
You are given an array prices where prices[i] is the price of a given stock
 on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions
 as you like, but you need to pay the transaction fee for each transaction.
Note:
You may not engage in multiple transactions simultaneously (i.e., you must 
sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/
//DP
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = INT_MIN/2; //in the current day, if we hold, the profit.
        int sold = 0;  //in the current day, if we sold, the profit.
        for(int i=0; i<prices.size(); i++) {
            int preHold = hold;
            int preSold = sold;
            hold = max(hold, preSold-prices[i]); //buy
            sold = max(preSold, preHold + prices[i]- fee); //sell.
        }
        return sold;
    }
};