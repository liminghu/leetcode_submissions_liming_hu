// https://leetcode.com/problems/sparse-matrix-multiplication

class Solution {

public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        if(mat1.empty() || mat2.empty()) 
            return vector<vector<int>>();
        vector<vector<int>> ret(mat1.size(), vector<int>( mat2[0].size() ) );
        for(int i=0; i<mat1.size(); i++) {
            for(int k=0; k<mat2.size(); k++) {
                if(mat1[i][k] == 0)
                    continue;
                for(int l=0; l<mat2[0].size(); l++) {
                    if(mat2[k][l] == 0)
                        continue;
                    ret[i][l] += mat1[i][k]*mat2[k][l]; 
                }
            }
        }
        return ret;
    }
};