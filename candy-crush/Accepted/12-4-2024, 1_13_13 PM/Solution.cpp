// https://leetcode.com/problems/candy-crush

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool crushable = true;
        int m = board.size();
        int n = board[0].size();
        while(crushable) {
            crushable = false;
            for(int i=0; i<m; i++) {
                for(int j=0; j<n-2; j++) {
                    int num1 = abs(board[i][j]);
                    int num2 = abs(board[i][j+1]);
                    int num3 = abs(board[i][j+2]);
                    if(num1==num2 && num1==num3 && num1 != 0) {
                        board[i][j]   = -num1;
                        board[i][j+1] = -num1;
                        board[i][j+2] = -num1;
                        crushable = true;
                    }
                }
            }
            for(int j=0; j<n; j++) {
                for(int i=0; i<m-2; i++) {
                    int num1 = abs(board[i][j]);
                    int num2 = abs(board[i+1][j]);
                    int num3 = abs(board[i+2][j]);
                    if(num1==num2 && num1==num3 && num1 != 0) {
                        board[i][j]   = -num1;
                        board[i+1][j] = -num1;
                        board[i+2][j] = -num1;
                        crushable = true;
                    }
                }
            }  
            if(crushable) {
                for(int j=0; j<n; j++) { //for each column.
                    int it = m-1;
                    for(int i=m-1; i>=0; i--) {
                        if(board[i][j] > 0) {
                            board[it][j] = board[i][j];
                            it--;
                        }
                    }
                    for(int k=it; k>=0; k--)
                        board[k][j] = 0;
                }
            }          
        }
        return board;
    }
};