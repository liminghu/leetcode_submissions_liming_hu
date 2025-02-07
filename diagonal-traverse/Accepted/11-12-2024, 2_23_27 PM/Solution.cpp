// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> res; //row*col.
        //(0,0) -> (row-1, col-1);      row+col-1-1;
        int r = 0; 
        int c = 0;
        bool up = true;
        while(r < row && c < col) {
            if(up) {
                while(r>0 && c < col-1) {
                    res.push_back(mat[r][c]);
                    r--;
                    c++;
                }
                res.push_back(mat[r][c]);
                if(c == col-1)
                    r++;
                else
                    c++;
            } else {
               while(r<row-1 && c >0) {
                    res.push_back(mat[r][c]);
                    r++;
                    c--;
                }
                res.push_back(mat[r][c]);
                if(r == row-1)
                    c++;
                else
                    r++;                
            }
            up = !up;
        }
        return res;

    }
};