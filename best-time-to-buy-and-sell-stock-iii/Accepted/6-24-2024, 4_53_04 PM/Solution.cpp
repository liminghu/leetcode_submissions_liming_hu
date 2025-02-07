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
      
        for(int price: prices) {
            t1cost = min(t1cost, price);
            t1profit = max(t1profit, price-t1cost);

            t2cost = min(t2cost, price-t1profit);
            t2profit = max(t2profit, price-t2cost);
        };

        return t2profit;
        
    }
};