// https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s

class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int expected = (m+n)/2;     //(3+3)/2 = 3
        if( (m+n-1)%2==1) 
            return false;

        vector<vector<vector<int>>> dp(m+1, vector(n+1, vector<int>(2, 0)));
        for(int i=0; i<m; i++) { //Let's iterate through grid and remember the minimum and the maximum number of 1-s we've seen for each tile.
            for(int j=0; j<n; j++) {
                dp[i+1][j+1][0] = min(dp[i+1][j][0], dp[i][j+1][0]);
                dp[i+1][j+1][1] = max(dp[i+1][j][1], dp[i][j+1][1]);
                if(grid[i][j]==1) {
                    dp[i+1][j+1][0]++;   //min
                    dp[i+1][j+1][1]++;   //max
                }
            }
        } 
        return dp[m][n][0] <= expected && expected <= dp[m][n][1];
    }
};