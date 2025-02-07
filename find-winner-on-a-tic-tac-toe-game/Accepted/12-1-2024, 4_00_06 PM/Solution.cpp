// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3; //board size.
        //record board status.
        vector<int> rows(n);
        vector<int> cols(n);
        int diag = 0;
        int anti_diag = 0;

        int player = 1;
        for(int i=0; i<moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            rows[row] += player;
            cols[col] += player;
            if(row==col)
                diag += player;
            if(row+col == n-1)
                anti_diag += player;
            if(abs(rows[row]) == n || abs(cols[col])==n || abs(diag) == n || abs(anti_diag)==n)
                return player == 1? "A": "B";
            player *= -1;
        }
        return moves.size() == n*n? "Draw": "Pending";
    }

};