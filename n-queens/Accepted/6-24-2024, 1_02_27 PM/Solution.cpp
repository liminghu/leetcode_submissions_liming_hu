// https://leetcode.com/problems/n-queens

class Solution {
public:
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/
    vector<vector<string>> ans = {};
    vector<string> path = {};
    vector<vector<string>> solveNQueens(int n) { //1 <= n <= 9
        int start = 0;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        backtrack(n, start, board);
        return ans;
        
    }
    void backtrack(int n, int row, vector<vector<char>>& board) {
        if(row == n) {
            ans.push_back(arraytoList(board));
            return;
        };

        for(int col=0; col<n; col++) {
            //place queen
            if(!isValid(n, board, row, col))
                continue;
            board[row][col] = 'Q';
            backtrack(n, row+1, board);
            board[row][col] = '.';
        }
    }


    bool isValid(int n, vector<vector<char>>& board, int row, int col) { //can we place the queen at (row, col)?

        //we do not need to check the current row.

        for(int i=0; i<n; i++) { //check the current col.
            if(board[i][col] == 'Q')
                return false;
        };

        //check diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        //check anti-dignonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;

    }

    vector<string> arraytoList(vector<vector<char>> board) {
        vector<string> ans;

        for(int row =0; row<board.size(); row++) {
            string cur_row = "";
            for(int col =0; col<board[0].size(); col++) {
                cur_row= cur_row+board[row][col];
            }
            ans.push_back(cur_row);
            cur_row = "";
        }
        return ans;
    }
};