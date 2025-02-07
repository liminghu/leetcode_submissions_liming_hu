// https://leetcode.com/problems/minimum-falling-path-sum-ii

class Solution {
public:
/*
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
A falling path with non-zero shifts is a choice of exactly one element from each row of grid such 
that no two elements chosen in adjacent rows are in the same column.
*/
    int minFallingPathSum(vector<vector<int>>& grid) { //n == grid.length == grid[i].length
                                                        //1 <= n <= 200
                                                        //-99 <= grid[i][j] <= 99
        int sz = grid.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        dp[0] = grid[0];

        for(int i=1; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                //dp[i][j] = min(dp[i-1][0..sz]), exclude j   + grid[i][j];
                int minPre = INT_MAX;
                for(int k=0; k<sz; k++) {
                    if(k!=j) {
                        minPre = min(minPre, dp[i-1][k]);
                    };
                }
                dp[i][j] = minPre + grid[i][j];
            }
        };

        int ret = INT_MAX;
        for(int k=0; k<sz; k++) {
            ret = min(ret, dp[sz-1][k]);       
        } 

        return ret;
        
    }
};