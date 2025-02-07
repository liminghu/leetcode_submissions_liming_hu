// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    /*
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
    Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
    */
    int minCostClimbingStairs(vector<int>& cost) { //0 <= cost[i] <= 999; 2 <= cost.length <= 1000
        int ans = 0;
        int sz = cost.size();
        
        vector<int> dp_total(sz+1,0);
        
        if(sz == 2) {
            if( cost[0] < cost[1] )
                ans = cost[0];
            else
                ans = cost[1];
            return ans;
        }
        
        dp_total[1] = min(cost[0], cost[1]);
        dp_total[2] = min(dp_total[0]+cost[2], cost[1]);
       // dp_total[3] = min(dp_total[1]+cost[3], dp_total[2]);
        
        for(int i=3; i<sz; i++) {
            dp_total[i] = min(dp_total[i-2]+cost[i], dp_total[i-1]);
        };
        
        ans = dp_total[sz-1];
        
        
        //dp_total[sz-1] = dp_total[sz-2]+cost[sz-2], dp_total[sz-1]
        return ans;
        
        
    }
};