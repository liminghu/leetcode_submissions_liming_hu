// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        //r*c
        if(r*c != m*n)
            return mat;
        vector<vector<int>> rets(r, vector<int>(c, 0));
        int idx = 0;
        while(idx<m*n) {
            int element = mat[idx/n][idx%n];
            rets[idx/c][idx%c] = element;
            idx++;
        }
        return rets;
    }
};