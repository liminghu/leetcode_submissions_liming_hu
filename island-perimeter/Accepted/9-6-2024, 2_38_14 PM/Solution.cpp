// https://leetcode.com/problems/island-perimeter

/*You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly 
one island (i.e., one or more connected land cells).
The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with 
side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
There is exactly one island in grid.
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) 
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        int conn = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    area++;
                    if(i-1>=0 && grid[i-1][j]==1)
                        conn++;
                    if(j-1>=0 && grid[i][j-1]==1)
                        conn++;                    
                    if(i+1<m && grid[i+1][j]==1)
                        conn++;                    
                    if(j+1<n && grid[i][j+1]==1)
                        conn++;                        
                }
            }
        }
        return area*4-conn;
    }
};