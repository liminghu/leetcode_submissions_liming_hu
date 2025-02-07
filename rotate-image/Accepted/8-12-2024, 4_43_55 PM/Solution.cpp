// https://leetcode.com/problems/rotate-image

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
          n == matrix.length == matrix[i].length
          1 <= n <= 20
          -1000 <= matrix[i][j] <= 1000
        */
        int sz = matrix.size();
        //(i, j)->(j, i) 
        for(int i=0; i<sz; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //(i, j) -> (i, n-1,j)
        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz/2; j++) {
                swap(matrix[i][j], matrix[i][sz-1-j]);
            }
        }



    }
};