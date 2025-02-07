// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island

/*You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.*/
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        /*  m == grid.length
            n == grid[i].length
            1 <= m, n <= 30
            grid[i][j] is either 0 or 1
            */

        //check the number of islands.
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
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
                    if(j+1<n && grid[i][j+1] == 1 && i+1<m && grid[i+1][j]==1 && grid[i+1][j+1]==0)
                        return 1; 
                } 
            }
        }
        return 2;
    }

};