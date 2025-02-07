// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //top left
        //bottom right
        int m = dungeon.size();
        int n = dungeon[0].size();
        //// Add dummy row and column at bottom and right side
        auto dp = vector(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                int need = min(dp[i+1][j], dp[i][j+1])-dungeon[i][j];
                dp[i][j] =   need<=0? 1: need;  
            }
        }
        return dp[0][0];
    }
};