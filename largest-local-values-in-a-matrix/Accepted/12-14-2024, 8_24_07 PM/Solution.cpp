// https://leetcode.com/problems/largest-local-values-in-a-matrix

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2, 0));
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<n-1; j++) {
                maxLocal[i-1][j-1] = findMax(grid, i, j);
            }
        };         
        return maxLocal;
    }
    int findMax(vector<vector<int>>& grid, int r, int c) {
        int maxVal = 0;
        for(int i=r-1; i<=r+1; i++) {
            for(int j=c-1; j<=c+1; j++) {
                maxVal = max(maxVal, grid[i][j]);
            }
        }
        return maxVal;
    }
};