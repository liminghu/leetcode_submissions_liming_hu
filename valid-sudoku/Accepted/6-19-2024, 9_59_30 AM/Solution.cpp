// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        //Each row must contain the digits 1-9 without repetition.        
        for(int i=0; i<rows; i++) {
            unordered_set<char> row_char;
             for(int j=0; j<cols; j++) {
                if(board[i][j] != '.') {
                    if(row_char.find(board[i][j])==row_char.end())
                        row_char.insert(board[i][j]);
                    else
                        return false;
                }                
             }
             row_char.clear();
        }

        //Each column must contain the digits 1-9 without repetition.
        for(int j=0; j<cols; j++) {
            unordered_set<char> col_char;
             for(int i=0; i<rows; i++) {
                if(board[i][j] != '.') {
                    if(col_char.find(board[i][j])==col_char.end())
                        col_char.insert(board[i][j]);
                    else
                        return false;
                }           
             }
             col_char.clear();
        }
        //Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

        for(int k=0; k<9; k++) {
            unordered_set<char> grid_char;
            for(int j=0+k/3*3; j<(3+k/3*3); j++) {            
                for(int i=(0+k%3)*3; i<(1+k%3)*3; i++) {
                    if(board[i][j] != '.') {
                        if(grid_char.find(board[i][j])==grid_char.end())
                            grid_char.insert(board[i][j]);
                        else
                            return false;
                    }           
                }             
            }
            grid_char.clear();
        }

        return true;
        
    }
};