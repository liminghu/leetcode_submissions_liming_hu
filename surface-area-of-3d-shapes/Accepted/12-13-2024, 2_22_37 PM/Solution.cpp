// https://leetcode.com/problems/surface-area-of-3d-shapes

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //each tower: v= grid[i][j], area: 4*v +2.
        //2 adjacent tower will hide the area of connected part: min(v1, v2)*2
        int res = 0;
        int n = grid.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j])
                    res += 4*grid[i][j] + 2;
                if(i>=1)
                    res -= min(grid[i][j], grid[i-1][j])*2;
                if(j>=1)
                    res -= min(grid[i][j], grid[i][j-1])*2;                
            }
        }
        return res;
    }
};