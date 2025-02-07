// https://leetcode.com/problems/rotting-oranges

/*
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        /*  m == grid.length
            n == grid[i].length
            1 <= m, n <= 10
            grid[i][j] is 0, 1, or 2.
        */
        int m = grid.size();
        int n = grid[0].size();
        int mins = 0;
        int num_good = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if(grid[i][j] == 1)
                    num_good++; 
                else if(grid[i][j] == 2) 
                    q.push({i,j});
            }
        };

        q.push({-1, -1}); //mark the end of current timestamp.

        if(num_good == 0)
            return 0;
        
        while(!q.empty()) {    
            pair<int,int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
            if(i == -1) {
                mins++;
                if(!q.empty()) {
                    q.push({-1, -1});
                }
            } else {
                //4 neighbors.
                //grid[i+1][j]
                if(i+1<m && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    num_good--;
                    q.push({i+1, j});
                } 
                //grid[i-1][j] 
                if(i-1>=0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    num_good--;
                    q.push({i-1, j});
                } 
                //grid[i][j+1] 
                if(j+1<n && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    num_good--;
                    q.push({i, j+1});
                } 
                //grid[i][j-1] 
                if(j-1>=0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    num_good--;
                    q.push({i, j-1});
                } 
            }
        }//end while

        return num_good == 0? mins-1: -1;
    }
};