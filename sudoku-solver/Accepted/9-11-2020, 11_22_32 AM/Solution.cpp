// https://leetcode.com/problems/sudoku-solver



class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       //DFS+backtracking
	   //store constraints.
	   rows_ = vector<vector<int>>(9, vector<int>(10)); //1: used. 0: not used.
	   cols_ = vector<vector<int>>(9, vector<int>(10));
	   boxes_ = vector<vector<int>>(9, vector<int>(10));
	   
	   //initialize the constraints.
	   for(int i = 0; i<9; i++)
		   for(int j = 0; j<9; j++) {
			   const char c = board[i][j];
			   if(c != '.') {
					int n = c - '0';
					int bx = j / 3;
					int by = i / 3;
					rows_[i][n] = 1; //used.
					cols_[j][n] = 1;
					boxes_[by *3 + bx][n] = 1;
			   }
		   }
		fill(board, 0, 0);
		
    }
private:
	vector<vector<int>> rows_;
	vector<vector<int>> cols_;
	vector<vector<int>> boxes_;
	bool fill(vector<vector<char>>& board, int x, int y) {
		if(y==9) //we filled all.
			return true; 
		
		//next pos.
		int nx =(x + 1) % 9;
		int ny = (nx == 0) ? y + 1 : y;  //next row?
		
		if(board[y][x] != '.' ) return fill(board, nx, ny);
		
		//try all possible char.
		for(int i=1; i<=9; i++) {
			int bx = x / 3;
			int by = y / 3;	
			int box_key = by *3 + bx;
			if(!rows_[y][i] && !cols_[x][i] && !boxes_[box_key][i]) {
					rows_[y][i] = 1; //used.
					cols_[x][i] = 1;
					boxes_[box_key][i] = 1;
					board[y][x] = i+ '0';
					if (fill(board, nx, ny)) return true;
					board[y][x] = '.';  //backtracking.
					rows_[y][i] = 0; //not used.
					cols_[x][i] = 0;
					boxes_[box_key][i] = 0;
			}
		}
		return false;
	}
};
