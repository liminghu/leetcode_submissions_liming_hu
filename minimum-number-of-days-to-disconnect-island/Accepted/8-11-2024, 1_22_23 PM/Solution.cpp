// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island

/*You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.*/
class Solution {
public:
   const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minDays(vector<vector<int>>& grid) {
        /*  m == grid.length
            n == grid[i].length
            1 <= m, n <= 30
            grid[i][j] is either 0 or 1
            */
        int rows = grid.size();
        int cols = grid[0].size();

        // Count initial islands
        int initialIslandCount = countIslands(grid);

        // Already disconnected or no land
        if (initialIslandCount != 1) {
            return 0;
        }

        // Try removing each land cell
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) continue;  // Skip water

                // Temporarily change to water
                grid[row][col] = 0;
                int newIslandCount = countIslands(grid);

                // Check if disconnected
                if (newIslandCount != 1) return 1;

                // Revert change
                grid[row][col] = 1;
            }
        }

        return 2;
/*
        //check the number of islands.
        int m = grid.size();
        int n = grid[0].size();
       // visited.resize(m, vector<int>(n));
        int num = numIslands(grid);
        if(num>1 || num==0)
            return 0;

        int res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {   
                if(grid[i][j]>=1) {
                    grid[i][j] = 0;
                    //grid[i][j] neighbors.
                    // i-1, j
                    // i+1, j
                    // i j-1
                    // i j+1
                    //if they are land, are they still connected?
                    num = numIslands(grid);
                    if(num >= 2 || num == 0)
                        return 1;
                    grid[i][j] = 1;
                } 
            }
        }
        return 2;*/
    }

    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        // Iterate through all cells
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Found new island
                if (!visited[row][col] && grid[row][col] == 1) {
                    exploreIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    // Helper method to explore all cells of an island
    void exploreIsland(vector<vector<int>>& grid, int row, int col,
                       vector<vector<bool>>& visited) {
        visited[row][col] = true;

        // Check all adjacent cells
        for (const auto& direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            // Explore if valid land cell
            if (isValidLandCell(grid, newRow, newCol, visited)) {
                exploreIsland(grid, newRow, newCol, visited);
            }
        }
    }

    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col,
                         const vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        // Check bounds, land, and not visited
        return row >= 0 && col >= 0 && row < rows && col < cols &&
               grid[row][col] == 1 && !visited[row][col];
    }

    int numIslands(vector<vector<int>>& grid) {
        /*  m == grid.length
            n == grid[i].length
            1 <= m, n <= 30
            grid[i][j] is either 0 or 1
            */

        //check the number of islands.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));

        int num = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    q.push(pair{i,j});
                    num++;
                }
                while(!q.empty()) {
                    pair<int,int> cur = q.front();
                    int x = cur.first;
                    int y = cur.second;                    
                    q.pop();
                    visited[x][y] = num;
                    //four neighbors.
                    if(x-1>=0 && !visited[x-1][y] && grid[x-1][y]==1)
                        q.push(pair{x-1, y});
                    if(x+1<m && !visited[x+1][y] && grid[x+1][y]==1)
                        q.push(pair{x+1, y});                   
                    if(y-1>=0 && !visited[x][y-1] && grid[x][y-1]==1)
                        q.push(pair{x, y-1});                   
                    if(y+1<n && !visited[x][y+1] && grid[x][y+1]==1)
                        q.push(pair{x, y+1});
                }
            }
        }
        return num;
    }

};