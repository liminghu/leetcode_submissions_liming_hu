// https://leetcode.com/problems/count-unguarded-cells-in-the-grid

class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        //guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
        //A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position 
        //unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));
        for(auto& guard:guards) {
            grid[guard[0]][guard[1]] = GUARD;
        };
        for(auto& wall:walls)
            grid[wall[0]][wall[1]] = WALL;
        for(auto& guard:guards) {
            markguarded(guard[0], guard[1], grid);
        }
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==UNGUARDED)  
                    count++;
            }
        }
        return count;
    }
    void markguarded(int row, int col, vector<vector<int>>& grid) {
        for(int r = row-1; r>=0; r--) {
            if(grid[r][col]==WALL || grid[r][col]==GUARD)
                break;
            grid[r][col]=GUARDED;
        }
       for(int r = row+1; r<grid.size(); r++) {
            if(grid[r][col]==WALL || grid[r][col]==GUARD)
                break;
            grid[r][col]=GUARDED;
        }        
        for(int c = col-1; c>=0; c--) {
            if(grid[row][c]==WALL || grid[row][c]==GUARD)
                break;
            grid[row][c]=GUARDED;
        }
       for(int c = col+1; c<grid[0].size(); c++) {
            if(grid[row][c]==WALL || grid[row][c]==GUARD)
                break;
            grid[row][c]=GUARDED;
        }              
    }
};