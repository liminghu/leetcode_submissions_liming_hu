// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

class Solution {
    long dp[1001][1001]; //how many ways to form target[0..i] using word[0:k]
    long count[1001][27];
    long M = 1e9+7;
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size();
        int m = words[0].size();
        for(auto word: words) {
            for(int i=0; i<m; i++)
                count[i+1][word[i]-'a'] += 1;
        };
        target = "#" + target;
        for(int k=0; k<=m; k++)
            dp[0][k] = 1;
        //dp[i][0]     0
        for(int i=1; i<=n; i++) {
            for(int k=1; k<=m; k++) {
                dp[i][k] = dp[i][k-1]; //if we do not use word[k] to form target[i];
                if ( count[k][target[i]-'a']>0 )
                    dp[i][k] += dp[i-1][k-1]*count[k][target[i]-'a'] %M;
                dp[i][k] %=M;
            }
        }
        return dp[n][m];
    }
};