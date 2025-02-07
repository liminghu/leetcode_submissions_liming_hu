// https://leetcode.com/problems/count-ways-to-build-good-strings

class Solution {
    int M = 1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1); //the number of different good strings that can be constructed with size i.
        //dp[i]   (dp[i-zero]  +  dp[i-one])
        dp[0] = 1;
        for(int i=1; i<=high; i++) {
            if(i>=zero)
                dp[i] += dp[i-zero];
            dp[i] %= M;
            if(i>=one)
                dp[i] += dp[i-one];
            dp[i] %= M;
        };
        int ret = 0;
        for(int i = low; i <= high; i++) {
            ret += dp[i];
            ret %= M;
        };
        return ret;
    }
};