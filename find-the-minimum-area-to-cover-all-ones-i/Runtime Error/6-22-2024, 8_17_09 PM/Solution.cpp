// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i

class Solution {
public:
    /*
    You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.
*/
 
 
    int minimumArea(vector<vector<int>>& grid) {
        int left = 0;
        int right = grid[0].size()-1; //2
        int rows = grid.size();
        int cols = grid[0].size();
        
        int top = 0;
        int bottom = grid.size()-1; //1
        
        while(left<grid[0].size()) {  //left
            //all columns are 0
            int i=0;
            for(; i<rows; i++) {
                if(grid[i][left])
                    break;                
            }
            if(grid[i][left] && i<rows)
                    break;
            left++;
        };
        
        while(right>=0) {          //right
            //all columns are 0
            int i=0;
            for(; i<rows; i++) {
                if(grid[i][right])
                    break;                
            }
            if(grid[i][right] && i<rows)
                    break;   
            right--;
        };
        
        while(top<grid.size()) { //top
            //all rows are 0
            int j=0;
            for(; j<cols; j++) {
                if(grid[top][j])
                    break;                
            }
            if(grid[top][j] && j<cols) break;
            top++;
        };
        
        while(bottom>=0) { //bottom
            //all rows are 0
            int j=0;
            for(; j<cols; j++) {
                if(grid[bottom][j])
                    break;                
            }
            
            if(grid[bottom][j] && j<cols) break;
            bottom--;
        };
        
        int area = (right-left+1)*(bottom-top+1);
        return area;
    }
};