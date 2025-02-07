// https://leetcode.com/problems/design-tic-tac-toe

/*
Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that the player with id player plays at the cell (row, col) of the board. 
The move is guaranteed to be a valid move, and the two players alternate in making moves. Return
0 if there is no winner after the move,
1 if player 1 is the winner after the move, or
2 if player 2 is the winner after the move.
2 <= n <= 100
player is 1 or 2.
0 <= row, col < n
(row, col) are unique for each different call to move.
At most n2 calls will be made to move.
Follow-up: Could you do better than O(n2) per move() operation?
*/
class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
public:
    TicTacToe(int n) {
        rows = vector(n, 0);
        cols = vector(n, 0);
        
    }
    
    int move(int row, int col, int player) {
        //0 if there is no winner after the move,
        //1 if player 1 is the winner after the move, or
        //2 if player 2 is the winner after the move.
        int toAdd = player==1? 1: -1;
        rows[row] += toAdd;
        cols[col] += toAdd;

        int size = rows.size();
        if(row==col)
            diagonal += toAdd;
        if(col == size - row - 1 )
            antiDiagonal += toAdd;
        
        if( abs(rows[row]) == size || abs(cols[col]) == size || abs(diagonal) == size || abs(antiDiagonal) == size )
            return player;
        
        return 0;
    }

};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */