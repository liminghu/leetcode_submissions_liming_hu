// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool r1 = true;
        bool r2 = true;
        bool r3 = true;
        bool r4 = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j])
                    r1 = false;
                if(mat[i][j] != target[n-1-j][i])
                    r2 = false;
                if(mat[i][j] != target[n-1-i][n-1-j])
                    r3 = false;
                if(mat[i][j] != target[j][n-1-i])
                    r4 = false;
            }    
        }
        return r1 || r2 || r3 || r4;
    }
};