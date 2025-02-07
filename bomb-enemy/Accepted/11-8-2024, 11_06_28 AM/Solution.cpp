// https://leetcode.com/problems/bomb-enemy

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols.
        if(m==0 || n == 0)
            return 0;
        int res = 0;
        int rowCount = 0; //the current row count of enemies can be killed.
        vector<int> colCount(n, 0); 
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(j==0 || grid[i][j-1] == 'W') { // a new row, or previous cell is a wall
                    rowCount = 0;
                    for(int k=j; k<n; k++) { //scan the whole current row until wall.
                        if(grid[i][k] == 'W')
                            break;
                        if(grid[i][k] == 'E')
                            rowCount++;
                    }
                }

                //scan the current column.
                if(i==0 || grid[i-1][j] == 'W') { // a new col, or the previous column cell is a wall.
                    colCount[j] = 0;
                    for(int k=i; k<m; k++) {
                        if(grid[k][j] == 'W')
                            break;
                        if(grid[k][j] == 'E')
                            colCount[j]++;
                    }
                }

                if(grid[i][j] == '0') {
                    res = max(res, rowCount + colCount[j]);
                }
            }
        }
        return res;
    }
};