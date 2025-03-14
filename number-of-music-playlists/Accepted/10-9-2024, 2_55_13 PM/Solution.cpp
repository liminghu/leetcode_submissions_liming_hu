// https://leetcode.com/problems/number-of-music-playlists

/*
Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. 
To avoid boredom, you will create a playlist so that:
Every song is played at least once.
A song can only be played again only if k other songs have been played.
Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, 
return it modulo 109 + 7.

Example 1:
Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].

Example 2:
Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].

Example 3:
Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
 

Constraints:
0 <= k < n <= goal <= 100
*/
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int MOD = pow(10,9)+7;
        //dp[i][j]: the number of playlists of i songs with j different songs. answer: dp[goal][n] 
        vector<vector<long>> dp(goal+1, vector(n+1, (long)0));
        dp[0][0] = 1; //with 0 song, we can create a playlist of 0 song.
        for(int i=1; i<=goal; i++) {
            for(int j=1; j<=n; j++) {
                //with the number of playlists of i-1 songs with j-1 different songs.
                //we choose one song from n - (j-1) 
                dp[i][j] = ( dp[i-1][j-1] * ( n - (j-1) ) ) % MOD;
                if( j > k ) { //we have more than k diff. songs.
                    dp[i][j] = ( dp[i][j] + ( dp[i-1][j] * (j-k) ) % MOD  ) % MOD; 
                }
            }
        }

        return (int)dp[goal][n];
    }
};