// https://leetcode.com/problems/stone-game-ii

class Solution {
    int dp[101][101];
    int suffix[101];
public:
    int stoneGameII(vector<int>& piles) {
        //Alice starting first.
        //On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
        int n = piles.size();
        suffix[n] = 0;
        for(int i=n-1; i>=0; i--) 
            suffix[i] = suffix[i+1]+piles[i];
        return solve(0, 1, piles);
    }
    int solve(int i, int M, vector<int>& piles) {
        int n =piles.size();
        if(i==n)
            return 0;
        if( dp[i][M] != 0 )
            return dp[i][M];
        int sum = 0;
        for(int x=1; x<=2*M; x++) {
            if(i+x-1>=n)
                break;
            sum += piles[i+x-1];
            dp[i][M] = max(dp[i][M], sum+suffix[i+x]-solve(i+x, max(x,M), piles));
        }
        return dp[i][M];
    }
};