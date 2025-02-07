// https://leetcode.com/problems/set-matrix-zeroes



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
		if(matrix[0].size() == 0) return;
		
		bool firstRowZero = false;
		bool firstColZero = false;
		
		for(int i=0; i<matrix[0].size(); i++) {//first row.
			if(matrix[0][i] == 0) {
				firstRowZero = true;
				break;
			};
		}
		
		for(int i=0; i<matrix.size(); i++) {//first col.
			if(matrix[i][0] == 0) {
				firstColZero = true;
				break;
			};
		}

		for(int i=1; i<matrix.size(); i++)
			for(int j=1; j<matrix[0].size(); j++) {
				if(matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			};
		
		for(int j = 1; j < matrix[0].size(); j++) { //col
			if(matrix[0][j] == 0) {
				for(int i=1; i<matrix.size(); i++)
					matrix[i][j] = 0;
			}	
		}
		
		for(int i = 1; i < matrix.size(); i++) {
			if(matrix[i][0] == 0) {
				for(int j = 1; j < matrix[0].size(); j++)
					matrix[i][j] = 0;
			}	
		}
		
		if(firstRowZero) {
			for(int j=0; j < matrix[0].size(); j++)
					matrix[0][j] = 0;
		}
		
		if(firstColZero) {
			for(int i = 0; i < matrix.size(); i++)
					matrix[i][0] = 0;
		}
		
    }
};