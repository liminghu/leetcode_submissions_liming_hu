// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer <(n+1)/2; layer++) {  //layer start from 0
                //direction 1: same row, column: left to right
                //row: layer, col: layer to n-layer-1
                for(int col_ptr=layer; col_ptr <= n - layer - 1; col_ptr++) {
                    result[layer][col_ptr] = cnt++;
                }

                //direction 2: row: top to down, same col
                //row:layer+1 to n-layer-1     col: n-layer-1 
                for(int row_ptr=layer+1; row_ptr <= n - layer-1; row_ptr++) {
                    result[row_ptr][n-layer-1] = cnt++;
                }

                //direction 3: same row, column: right to left
                //row: n-layer-1;    col: n-layer-2 to layer;
                for(int col_ptr = n - layer - 2; col_ptr >= layer; col_ptr--) {
                    result[n-layer-1][col_ptr] = cnt++;
                }

                //direction 4: row: bottom to top,  same column
                //row: n-layer-2 to layer+1        col:layer 
                for(int row_ptr=n-layer-2; row_ptr>=layer+1; row_ptr--) {
                    result[row_ptr][layer] = cnt++;
                }

        }
        return result;
    }
};