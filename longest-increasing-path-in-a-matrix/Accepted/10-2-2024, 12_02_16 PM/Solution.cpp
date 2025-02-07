// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not 
move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/
class Solution {
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m,n;
    vector<vector<int>> memo;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo = vector(m, vector(n,-1));
        
        int ret = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ret = max(ret, dfs(matrix, i, j) );
            }
        };
        return ret;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if( memo[i][j] > 0 )
            return memo[i][j];
        
        int ret = 0;
        for(int k=0; k<4; k++) {
            int x = i + dirs[k].first;
            int y = j + dirs[k].second;
            if(x<0 || x>=m || y<0 || y>=n )
                continue;
            if( matrix[x][y] <= matrix[i][j] ) //cannot increase.
                continue;
            ret = max( ret, dfs(matrix, x, y) );
        };
        memo[i][j] = ret + 1;
        return memo[i][j];
    }
};