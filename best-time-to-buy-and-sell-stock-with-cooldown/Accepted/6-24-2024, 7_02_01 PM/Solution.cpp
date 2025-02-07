// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., 
you must sell the stock before you buy again).
*/
    int maxProfit(vector<int>& prices) {
        int held = -INT_MAX; //in this state, the agent holds a stock that it bought at some point before.
        int sold = -INT_MAX; // in this state, the agent has just sold a stock right before entering this state. And the agent holds no stock at hand.
        int reset = 0; // first of all, one can consider this state as the starting point, where the agent holds no stock and did not sell a stock before.
                        //More importantly, it is also the transient state before the held and sold.
                        //Due to the cooldown rule, after the sold state, the agent can not immediately acquire any stock, but is forced into the reset state.
                        //One can consider this state as a "reset" button for the cycles of buy and sell transactions.
       /*
       At any moment, the agent can only be in one state. The agent would transition to another state by performing some actions, namely:
       action sell: the agent sells a stock at the current moment. After this action, the agent would transition to the sold state.
       action buy: the agent acquires a stock at the current moment. After this action, the agent would transition to the held state.
       action rest: this is the action that the agent does no transaction, neither buy or sell. For instance, 
       while holding a stock at the held state, the agent might simply do nothing, and at the next moment the agent would remain in the held state.
       */

        for(int price:prices) {
            int preSold = sold;
            sold = held+price;
            held = max(held, reset-price);
            reset = max(reset, preSold);
       }

       return max(sold, reset);
    }
};