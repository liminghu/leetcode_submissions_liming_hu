// https://leetcode.com/problems/n-queens


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
			sols_.clear();
			board_ = vector<string>(n, string(n,'.'));
			cols_ = vector<int>(n,0);
			diag1_ = vector<int>(2*n-1,0);
			diag2_ = vector<int>(2*n-1,0);
			
			nqueens(n, 0);
			
			return sols_;
    }
private:
	vector<string> board_;
	vector<int> cols_;
	vector<int> diag1_;
	vector<int> diag2_;
	vector<vector<string>> sols_;
	
	//try to put the queen on y-th row.
	void nqueens(const int n, const int y) {
		if( y == n) {
			//find one solution, add to the ans set.
			sols_.push_back(board_);
			return;
		}
		
		//try every column
		for(int x=0; x<n; x++) {
			if(!available(x,y,n) ) continue;
			updateBoard(x,y,n,true);
			nqueens(n, y+1); 
			updateBoard(x,y,n,false); //backtracking
		}
	}
	
	bool available(int x, int y, int n) {
		return !cols_[x] && !diag1_[x+y] && !diag2_[x+n-1-y];
	}
	
	void updateBoard(int x,int y,int n,bool is_put) {
		cols_[x] = is_put;
		diag1_[x+y] = is_put; 
		diag2_[x+n-1-y] = is_put;
		board_[y][x] = is_put? 'Q' : '.';
	}
	
};