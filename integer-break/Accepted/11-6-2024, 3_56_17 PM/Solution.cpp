// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) { //n>=2
        if(n==2)
            return 1;
        if(n==3)
            return 2;
            
        vector<int> dp(n+1, 0);
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4; i<=n; i++) {
            for(int j=2; j<=i-2; j++) //j < i, i-j < i
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
        }
        return dp[n];
    }
};