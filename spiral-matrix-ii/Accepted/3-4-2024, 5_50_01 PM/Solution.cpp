// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:

    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }


    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        int dir[4][2] = { //{x,y}   row, col
           {0, 1},   //left right
           {1, 0},       //top down
           {0, -1},  //right left
           {-1, 0}  //bottom up
        };
        int d = 0;
        int row = 0;
        int col = 0; 

        while (cnt <=n*n) {
            result[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1]+n, n);
            //change directions
            if (result[r][c]!=0)  {
                d= (d+1)%4;
            }
            row += dir[d][0];
            col += dir[d][1];
            
        }
        return result;
    }
};