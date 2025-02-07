// https://leetcode.com/problems/magic-squares-in-grid

/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, 
column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
*/
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        /*  row == grid.length
            col == grid[i].length
            1 <= row, col <= 10
            0 <= grid[i][j] <= 15
        */
        int row = grid.size();
        int col = grid[0].size();

        if(row < 3 || col < 3)
            return 0;
        
        int res = 0;

        for(int i=0; i+2<=row-1; i++) {
            for(int j=0; j+2<=col-1; j++) {
                if (isMagicSquare(grid, i, j) )
                res++;
            }
        }
        return res;
    }

    bool isMagicSquare(vector<vector<int>>& grid, int startr, int startc) {
        int row = grid.size();
        int col = grid[0].size();

        if(startr+2 >row-1 || startc+2 > col-1)
            return false;

        //are they all distinct?
        unordered_set<int> s;
       for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(grid[startr+i][startc+j] > 9 || grid[startr+i][startc+j] < 1)
                    return false;

                if(s.find(grid[startr+i][startc+j]) == s.end())
                    s.insert(grid[startr+i][startc+j]);
                else
                    return false;
            }
        }

        //check row
        int first_sum = -1;
        for(int i=0; i<3; i++) {
            int sum = 0;
            for(int j=0; j<3; j++) {
                sum += grid[startr+i][startc+j]; 
            }
            if(first_sum < 0)
                first_sum = sum;
            if(sum!=first_sum)
                return false;
        }

        //check diagonals
        int sum = 0;
        for(int i=0, j=0; i<3; i++, j++) {
            sum += grid[startr+i][startc+j]; 
        }
        if(sum!=first_sum)
            return false;

        //check anti-diagonals
        sum = 0;
        for(int i=0, j=2; i<3; i++, j--) {
            sum += grid[startr+i][startc+j]; 
        }
       if(sum!=first_sum)
            return false;
        //check col   
       for(int j=0; j<3; j++) {
            int sum = 0;
            for(int i=0; i<3; i++) {
                sum += grid[startr+i][startc+j]; 
            }
            if(sum!=first_sum)
                return false;
        }    

        return true;         
    }
};