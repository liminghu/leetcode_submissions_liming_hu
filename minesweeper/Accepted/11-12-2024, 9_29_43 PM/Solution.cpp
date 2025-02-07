// https://leetcode.com/problems/minesweeper

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').
        int x = click[0];
        int y = click[1];
        char curr = board[x][y];
        if(curr == 'M') {//unrealed Mine
            board[x][y] = 'X';
            return board;
        }

        int count = findMines(board, x, y);
        if(count == 0)  //revealed blank square.
            reveal(board, x, y);
        else //digit 1~8
            board[x][y] = (char)('0'+count);
        return board;
    }
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int findMines(vector<vector<char>>& board, int i, int j) {
        int count = 0;
        for(auto dir:dirs) {
            int x = i+dir[0];
            int y = j+dir[1];
            if(x>=0 && x<board.size() && y>=0 && y <board[0].size()) {
                if(board[x][y] == 'M' || board[x][y] == 'X') {
                    count++;
                }
            }
        }
        return count;
    }
    void reveal(vector<vector<char>>& board, int i, int j) {
        if(i<0 || i>=board.size() || j<0 || j >=board[0].size())
            return;
        if(board[i][j] == 'M' || board[i][j] == 'B')
            return;
        int count = findMines(board, i, j);
        if( count != 0 ) {
            board[i][j] = (char)('0'+count);
            return;
        }
        board[i][j] = 'B';
        for(auto dir:dirs) {
            int x = i+dir[0];
            int y = j+dir[1];
            reveal(board, x, y);
        }
    }
};