// https://leetcode.com/problems/score-after-flipping-matrix

/*
You are given an m x n binary matrix grid.
A move consists of choosing any row or column and toggling each value in that row or 
column (i.e., changing all 0's to 1's, and all 1's to 0's).
Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
Return the highest possible score after making any number of moves (including zero moves).
m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.
*/
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = (1<<(m-1))*n;  //we need to first flip all the highest bit to 1 if it is not.
        for(int j=1; j<m; j++) { //for other bits.
            int val = 1 << (m-1-j); //the val of the other bit gained.
            int set = 0;

            for(int i=0; i<n; i++) { //for all the rows.
                if(grid[i][j] == grid[i][0])  //if the other bit is the same as the highest bit.
                    set++;
            }
            res += max(set, n-set)*val;
        }
        return res;
    }
};