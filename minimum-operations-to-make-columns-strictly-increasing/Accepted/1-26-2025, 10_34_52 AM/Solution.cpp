// https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n; j++) {
                int prev = grid[i+1][j];
                grid[i+1][j] = max(grid[i+1][j], grid[i][j]+1);
                ret += grid[i+1][j] - prev;
            };
        };
        return ret;
    }
};