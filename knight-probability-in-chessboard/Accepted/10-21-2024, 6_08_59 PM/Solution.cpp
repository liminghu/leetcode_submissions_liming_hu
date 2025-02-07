// https://leetcode.com/problems/knight-probability-in-chessboard

/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is 
(0, 0), and the bottom-right cell is (n - 1, n - 1).
A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
The knight continues moving until it has made exactly k moves or has moved off the chessboard.
Return the probability that the knight remains on the board after it has stopped moving.

 Example 1:
Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

Example 2:
Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
 
Constraints:
1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n - 1
*/
class Solution {
public:
    double knightProbability(int N, int K, int row, int column) {
        auto dp1=vector<vector<double>>(N, vector<double>(N, 0));
        dp1[row][column] = 1;
        auto dirs = vector<vector<int>>({ {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, 
                      {-1, -2}, {-1, 2}, {1, -2}, {1, 2}}); 
        for(int k=0; k<K; k++) {
            auto dp2=vector<vector<double>>(N, vector<double>(N, 0));
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    for(int d=0; d<8; d++) {
                        int x = i+dirs[d][0];
                        int y = j+dirs[d][1];
                        if(x<0 || x>=N || y<0 || y>=N)
                            continue;
                        dp2[i][j] += dp1[x][y]*0.125;                        
                    }
                }
            }
            dp1 = dp2;
        }
        
        double res = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                res += dp1[i][j];
            }
        }
        return res;
    }
};