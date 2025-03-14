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
            int a = dp[max(0, i-1)]+costs[0];
            int b = dp[max(0, i-7)]+costs[1];
            int c = dp[max(0, i-30)]+costs[2];
            dp[i] = min(a, min(b,c));
        }
        return dp[days.back()];
    }
};