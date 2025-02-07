// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
    void solveSudoku(vector<vector<char>>& board) {//board.length == 9;  //board[i].length == 9 //board[i][j] is a digit or '.'.
                                                    //It is guaranteed that the input board has only one solution.
        backtrack(board);    
    }

    bool backtrack(vector<vector<char>>& board) {
        for(int row=0; row<board.size(); row++) {
             for(int col=0; col<board[0].size(); col++) {
                if(board[row][col]!='.')
                    continue;
                for(char k='1'; k<='9'; k++) {
                    if(!isValid(board, row, col, k))
                        continue;
                    board[row][col] = k;
                    if(backtrack(board))
                        return true;
                    board[row][col] = '.';
                }
                return false;
             }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, int val) {

        //row
        for(int j=0; j<9; j++) {
            if(board[row][j]== val)
                return false;
        }
        //col
        for(int i=0; i<9; i++) {
            if(board[i][col]== val)
                return false;
        }

        //3*3 only need to check the current 3*3
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i=startRow; i<startRow+3; i++) {
            for(int j=startCol; j<startCol+3; j++) {
                if( board[i][j] == val )
                    return false;
            }
        }
        return true;
    }
};