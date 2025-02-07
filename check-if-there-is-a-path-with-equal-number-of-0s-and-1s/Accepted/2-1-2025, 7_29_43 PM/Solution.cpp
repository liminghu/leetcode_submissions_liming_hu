// https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s

class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int expected = (m+n)/2;     //(3+3)/2 = 3
        if( (m+n-1)%2==1) 
            return false;

        vector<vector<int>> memo(n+1, vector<int>(2, 0));
        for(int r=1; r<=m; r++) { //Let's iterate through grid and remember the minimum and the maximum number of 1-s we've seen for each tile.
            for(int c=1; c<=n; c++) {
                memo[c][0] = min(memo[c][0], memo[c-1][0]);
                memo[c][1] = max(memo[c][1], memo[c-1][1]);
                if(grid[r-1][c-1]==1) {
                    memo[c][0]++;   //min
                    memo[c][1]++;   //max
                }
            }
        } 
        return memo[n][0]<=expected && expected<= memo[n][1];
    }
};