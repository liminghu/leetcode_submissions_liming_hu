// https://leetcode.com/problems/unique-paths-ii

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or 
right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square 
that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //The robot can only move either down or right at any point in time.
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(obstacleGrid[i][j] == 0) {
                    if(i==m-1 && j==n-1)
                        dp[m-1][n-1] = 1;
                    else if(i==m-1) //j<=n-2;
                        dp[i][j] = dp[i][j+1];
                    else if(j==n-1) //i<=m-2;
                        dp[i][j] = dp[i+1][j];
                    else
                        dp[i][j] = dp[i+1][j] + dp[i][j+1];
                };
            }
        }
        return dp[0][0];
    }
};