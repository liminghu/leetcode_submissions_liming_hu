// https://leetcode.com/problems/paint-house

class Solution {
public:
/*
There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. 
The cost of painting each house with a certain color is different. You have to paint all the houses 
such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.
For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the 
cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.
*/
    int minCost(vector<vector<int>>& costs) { //costs.length == n
                                              //costs[i].length == 3
                                              //1 <= n <= 100
                                              //1 <= costs[i][j] <= 20
        int sz = costs.size();
        //int K = costs[0].size();
        vector<vector<int>> dp(sz, vector<int>(3, 0));
        //dp.push_back(costs[0]);
        dp[0][0] = costs[0][0]; dp[0][1] = costs[0][1];  dp[0][2] = costs[0][2]; 
        for(int i=1; i<sz; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2])+ costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2])+ costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1])+ costs[i][2];
        }
        int ret = 0;
        ret = min(dp[sz-1][0], dp[sz-1][1]);
        ret = min(ret, dp[sz-1][2]);
        
        return ret;
    }
};