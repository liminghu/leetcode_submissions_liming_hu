// https://leetcode.com/problems/sparse-matrix-multiplication

class Solution {
unordered_map<int, vector< pair<int,int> > > m1;
unordered_map<int, vector< pair<int,int> > > m2;

public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        for(int i=0; i<mat1.size(); i++) {
            for(int j=0; j<mat1[0].size(); j++) {
                if(mat1[i][j] != 0) {
                    m1[i].push_back({j, mat1[i][j]});
                };
            }
        }
        for(int i=0; i<mat2.size(); i++) {
            for(int j=0; j<mat2[0].size(); j++) {
                if(mat2[i][j] != 0) {
                    m2[i].push_back({j, mat2[i][j]});
                };
            }
        }
        vector<vector<int>> ret(mat1.size(), vector<int>( mat2[0].size() ) );
        for(auto [key, val]: m1) { //unordered_map<int, vector<pair<int,int>>
            int row1 = key;
            for(auto p:val) {
                int col1 = p.first;
                int ele1 = p.second;
                for(auto second: m2[col1]) {
                    int row2 = col1;
                    
                    int col2 = second.first;
                    int ele2 = second.second;
                    ret[row1][col2] += ele1 * ele2;
                }
            }
        }
        return ret;
    }
/*    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
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
    }*/
};