// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INT_MAX);
        unordered_set set(days.begin(), days.end());
        dp[0] = 0;
        for(int i=1; i<=days.back(); i++) {
            if(set.find(i) == set.end()) {
                dp[i] = dp[i-1];
                continue;
            }
            int day1 = dp[max(0, i-1)]+costs[0];
            int day7 = dp[max(0, i-7)]+costs[1];
            int day30 = dp[max(0, i-30)]+costs[2];
            dp[i] = min(day1, min(day7,day30));
        }
        return dp[days.back()];
    }
};