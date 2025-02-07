// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        
        int ans = 0;
        //if(sz==2) {
        //    ans = min(cost[0], cost[1]);
        //    return ans;
        //}
        
        vector<int> dp_total(sz+1, 0);
        dp_total[0] = 0;
        dp_total[1] = 0;
        dp_total[2] = min(cost[0], cost[1]);
        //dp_total[2] = min(dp_total[0]+cost[2], dp_total[1]);
        //dp_total[3] = min(dp_total[1]+cost[3], dp_total[2]);
        for(int i=2; i<sz+1; i++) {
            int takeOneStep = dp_total[i - 1] + cost[i - 1];
            int takeTwoSteps = dp_total[i - 2] + cost[i - 2];
            dp_total[i] = min(takeOneStep, takeTwoSteps);
        }
        
        ans = dp_total[sz];
        return ans;
        
        
    }
};