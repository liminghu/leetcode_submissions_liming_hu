// https://leetcode.com/problems/word-search


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0) return false;
		h = board.size();
		w = board[0].size();
		for(int x=0; x<w; x++)
			for(int y=0; y<h; y++)
				if(search(board, word, 0, x, y) ) return true;
		
		return false;				
    };
private:
	int h;
	int w;
	bool search(vector<vector<char>>& board, const string& word, int d, int x, int y) {
		if(x<0 || x==w || y<0 || y==h || word[d] != board[y][x])
			return false;
		
		//found the last char of the word.
		if(d==word.length()-1) return true;
		
		char cur= board[y][x];
		board[y][x] = 0; //cur board pos used.
		bool found = search(board, word, d+1, x+1, y) 
					|| search(board, word, d+1, x-1, y) 
					|| search(board, word, d+1, x, y+1) 
					|| search(board, word, d+1, x, y-1);
		board[y][x] = cur;
		return found;
		
	
	}
};