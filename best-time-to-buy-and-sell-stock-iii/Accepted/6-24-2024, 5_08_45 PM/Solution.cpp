// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
    int maxProfit(vector<int>& prices) {
        //You may complete at most two transactions.
        //0: buy first.
        int t1cost = INT_MAX;
        //1: sell first
        int t1profit = 0;
        //2: buy second
        int t2cost = INT_MAX;
        //3: sell second.
        int t2profit = 0;
        int sz = prices.size();
      
      //best solution, a little hard to understand.
        for(int price: prices) { // Assume we only have 0 money at first
            t1cost = min(t1cost, price);
            t1profit = max(t1profit, price-t1cost); //the max profit we can get for the 1st transaction so far.

            t2cost = min(t2cost, price-t1profit); //the min cost we can get based on the first transaction, 
            t2profit = max(t2profit, price-t2cost); //The maximum if we've just sold 2nd stock so far.
        };

        return t2profit;
        
    }
};