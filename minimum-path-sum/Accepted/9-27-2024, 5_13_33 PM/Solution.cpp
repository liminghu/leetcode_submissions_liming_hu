// https://leetcode.com/problems/minimum-path-sum

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to 
bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j==n-1)
                    continue;
                else if(i==m-1)
                    dp[i][j] = dp[i][j+1]+grid[i][j];
                else if(j==n-1) 
                    dp[i][j] = dp[i+1][j]+grid[i][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};