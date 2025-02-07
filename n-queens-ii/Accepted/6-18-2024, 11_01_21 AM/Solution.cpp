// https://leetcode.com/problems/n-queens-ii

class Solution {
private:
    int size;
public:    
    int backtrack(int row, unordered_set<int>& cols, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals) {
        //base case: N queens have been placed.
        if(row == size) 
            return 1;

        int solutions = 0;
        for(int col=0; col<size; col++) {
            int curDiagonal = row -col;
            int curAntiDiagonal = row + col;

            if(cols.find(col)!=cols.end() || 
               diagonals.find(curDiagonal)!=diagonals.end() ||
               antiDiagonals.find(curAntiDiagonal)!=antiDiagonals.end())
               continue;
            
            cols.insert(col);
            diagonals.insert(curDiagonal);
            antiDiagonals.insert(curAntiDiagonal);

            solutions+= backtrack(row+1, cols, diagonals, antiDiagonals);
            cols.erase(col);
            diagonals.erase(curDiagonal);
            antiDiagonals.erase(curAntiDiagonal);
        };
        return solutions;
    }

    int totalNQueens(int n) { //1 <= n <= 9
        size = n;
        unordered_set<int> cols, diagonals, antiDiagonals;
        return backtrack(0, cols, diagonals, antiDiagonals);           
    }
};