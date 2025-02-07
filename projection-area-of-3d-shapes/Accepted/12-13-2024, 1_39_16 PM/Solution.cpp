// https://leetcode.com/problems/projection-area-of-3d-shapes

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;

        //from the top: non-zero value

        //from the side: the largest for each row.

        //from the front: the largest for each col.
        for(int i=0; i<n; i++) {
            int bestRow = 0;
            int bestCol = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j]>0)
                    res++;
                bestRow = max(bestRow, grid[i][j]);
                bestCol = max(bestCol, grid[j][i]);
            }
            res += bestRow + bestCol;
        }
        return res;
    }
};