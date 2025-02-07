// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
	  int row = matrix.size();
	  if(row == 0) return 0;
	  int col = matrix[0].size();
	  if(col == 0) return 0;
	  vector<int> heights(col, 0); //from top to current row, histogram height. 
	  
	  int max_area = 0;
	  for(int i = 0; i< row; i++) {
		for(int j = 0; j < col; j++) {
			if (matrix[i][j] == '1') {
				heights[j] ++;
			} else {
				heights[j] = 0;
			}
		}
		int area = largestRectangleArea(heights);
		max_area = max(max_area, area);
	  }
	  
	  return max_area;
   }
   
  int largestRectangleArea(vector<int>& heights) {
        //https://www.youtube.com/watch?v=TH9UaZ6JGcA&t=182s
        //increasing stack.
        //less, calculate.
        
        if( heights.size() == 0) return 0;
        if(heights.size()==1) return heights[0];
        
        int ans=0;
        heights.push_back(0);
        stack<int> mono_idx;
        
        
        for(int i=0; i<heights.size(); i++) { //add 0 to the end.
            while(!mono_idx.empty() && heights[mono_idx.top()]>heights[i]) {
                //start decreasing.
                int h = heights[mono_idx.top()]; mono_idx.pop();
                int l = mono_idx.empty()? -1: mono_idx.top(); //when empty i-(-1)-1 = i.
                ans = max(ans, h*(i-l-1)); //does not count i. 
            }
            mono_idx.push(i);
        }
        return ans;
        
    }
   
};