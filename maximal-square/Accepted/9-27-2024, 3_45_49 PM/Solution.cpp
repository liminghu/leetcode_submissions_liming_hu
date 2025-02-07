// https://leetcode.com/problems/maximal-square

/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sizes(m, vector<int>(n,0));
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                sizes[i][j] = matrix[i][j]-'0';
                if(sizes[i][j] == 0)
                    continue;
                if(i==0 || j== 0) {
                } else if(i==0) {
                    sizes[i][j] = sizes[i][j-1] +1;
                } else if(j==0) {
                    sizes[i][j] = sizes[i-1][j] +1;
                } else
                    sizes[i][j] = min( min(sizes[i][j-1], sizes[i-1][j]), sizes[i-1][j-1] ) + 1;
                ans = max(ans, sizes[i][j]*sizes[i][j]);
            }
        }
        return ans;
    }
};