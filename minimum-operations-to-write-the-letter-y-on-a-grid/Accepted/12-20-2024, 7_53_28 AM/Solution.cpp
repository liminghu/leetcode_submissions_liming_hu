// https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {//grid[r][c] is 0, 1, or 2.
        int ret = INT_MAX;
        for(int y=0; y<=2; y++) {
            for(int notY=0; notY<=2; notY++) {
                if(y==notY)
                    continue;
                ret = min(ret, getOperationsCount(grid, y, notY));               
            }
        }
        return ret;       
    }
    int getOperationsCount(vector<vector<int>>& grid, int y, int notY) {
        int ret = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(belongY(grid, i, j)) {
                    if( grid[i][j]!=y)
                        ret++;
                } else {
                    if( grid[i][j]!=notY)
                        ret++;
                }
            }
        }
        return ret;
    }
    bool belongY(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        if(i<=n/2 &&(i==j || i+j == n-1) || i>n/2 && j==n/2)
            return true;
        else
            return false;
    }
};