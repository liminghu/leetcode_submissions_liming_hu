// https://leetcode.com/problems/game-of-life

/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton 
devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented 
by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical,
 diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, 
where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the
 next state.
Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update
 some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would
 cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border).
  How would you address these problems?
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n;
        if(m==0) 
            n = 0;
        else
            n = board[0].size();
        //board[i][j]: 0(dead), 1(live)
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int lives = 0;
                for(int y=max(0, i-1); y<min(m, i+2); y++) {
                    for(int x=max(0, j-1); x<min(n, j+2); x++) {
                        lives += board[y][x] & 1;
                    }
                }
                //Any live cell with fewer than two live neighbors dies as if caused by under-population.
                int cell_live = board[i][j] & 1;
                if( cell_live && (lives-cell_live) < 2)
                    board[i][j] += 0; //second bit to 0. 
                //Any live cell with two or three live neighbors lives on to the next generation.
                if( cell_live && ( (lives-cell_live) == 2 || (lives-cell_live) == 3) )                
                    board[i][j] += 2; //second bit to 1. 
                //Any live cell with more than three live neighbors dies, as if by over-population.
                if( cell_live && ( (lives-cell_live) > 3 ) )                
                    board[i][j] += 0; //second bit to 0. 
                //Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                if( (cell_live==0) && ( (lives-cell_live) == 3 ) )
                    board[i][j] += 2; //second bit to 1.
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                board[i][j] >>= 1; //right shift 1 bit.
            }
        } 
    }
};