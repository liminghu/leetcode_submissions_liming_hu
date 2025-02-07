// https://leetcode.com/problems/spiral-matrix-iii

/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, 
and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue 
our walk outside the grid (but may return to the grid boundary later.). 
Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.
*/
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) { //rows*cols
        /*
        1 <= rows, cols <= 100
        0 <= rStart < rows
        0 <= cStart < cols
        */
        vector<vector<int>> res;
        int count = 1;
        int cur_r = rStart;
        int cur_c = cStart;
        int step = 0;
        int dir = 0;
        res.push_back({cur_r, cur_c});
        auto dirs = vector<pair<int,int>>{ {0,1},{1,0},{0,-1},{-1,0} }; //right, down, left, up.
        int num_elements = rows*cols;
        while(count < num_elements) {
            for(int k=0; k<step/2+1; k++) { //for one direction.
                cur_r += dirs[dir].first;
                cur_c += dirs[dir].second;
                if(cur_r >=0 && cur_r < rows && cur_c >=0 && cur_c < cols) {
                    res.push_back({cur_r, cur_c});
                    count++;
                }
            }
            step++;
            dir=(dir+1)%4;
        }
        return res;

    }
};