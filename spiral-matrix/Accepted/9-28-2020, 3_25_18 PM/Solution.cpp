// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
		if(matrix.size() == 0) 
			return ans;
		if(matrix[0].size() == 0) 
			return ans;
		
		int top = 0;
		int left = 0;
		int right = matrix[0].size()-1;
		int bottom = matrix.size()-1;
		while(left < right && top < bottom) {
			for(int i=left; i<right; i++) ans.push_back(matrix[top][i]);
			for(int i=top; i<bottom; i++) ans.push_back(matrix[i][right]);
			for(int i=right; i>left; i--) ans.push_back(matrix[bottom][i]);
			for(int i=bottom; i>top; i--) ans.push_back(matrix[i][left]);
			top++;
			bottom--;
			left++;
			right--;
		};
		
		if(left == right) { //one column left
			for(int i=top; i<=bottom; i++) ans.push_back(matrix[i][right]);
		} else if (top == bottom) {
			for(int i=left; i<=right; i++) ans.push_back(matrix[top][i]);
		}
		
		return ans;
    }
};