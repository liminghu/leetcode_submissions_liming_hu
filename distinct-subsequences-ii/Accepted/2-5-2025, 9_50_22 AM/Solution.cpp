// https://leetcode.com/problems/distinct-subsequences-ii

class Solution {
    int M = 1e9+7;
public:
    int distinctSubseqII(string s) { //1 <= s.length <= 2000
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        vector<int> last(26, -1);
        for(int i=0; i<n; i++) {
            int x = s[i]-'a';
            dp[i+1] = dp[i]*2 %M;
            if(last[x]>=0)
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= M;
            last[x] = i;
        }         
        dp[n]--;
        if(dp[n]<0)
            dp[n] += M;
        return dp[n];
    }
};