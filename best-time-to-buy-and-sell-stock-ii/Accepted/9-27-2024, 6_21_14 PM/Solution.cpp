// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of 
the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]>prices[i-1])
                res += prices[i]-prices[i-1];
        } 
        return res;
    /* int i=0;
     int valley = prices[0];
     int peak = prices[0];
     int maxprofit = 0;
     while(i<prices.size()-1) {
        while(i<prices.size()-1 && prices[i]>=prices[i+1])
            i++;
        valley = prices[i];
        while(i<prices.size()-1 && prices[i]<=prices[i+1])
            i++;
        peak = prices[i];
        maxprofit += peak-valley; 
     }
     return maxprofit;*/
     /*   int n = prices.size();
        int diff = 0;
        for(int i=1; i<n; i++) {
            if(prices[i]>prices[i-1])
                diff += prices[i]-prices[i-1];
        }
        return diff;*/
    }
};