// https://leetcode.com/problems/domino-and-tromino-tiling

/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent
 cells on the board such that exactly one of the tilings has both squares occupied by a tile.
1 <= n <= 1000
*/
class Solution {
public:
    int numTilings(int n) {
        int MODK = 1000000007;
        vector<vector<long>> dp(n+1, vector<long>(2, 0));
        dp[0][0] = dp[1][0] = 1;
        for(int i=2; i<=n; i++) {
            dp[i][0] = (dp[i-1][0] +dp[i-2][0] + 2*dp[i-1][1]) % MODK;
            dp[i][1] = (dp[i-2][0] + dp[i-1][1]) % MODK; 
        }
        return dp[n][0];        
    }
};