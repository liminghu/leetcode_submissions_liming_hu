// https://leetcode.com/problems/leftmost-column-with-at-least-a-one

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) { //1 <= rows, cols <= 100
        int ret = -1;
        vector<int> dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];
        int i=0;
        int j = cols-1;
        while(i<rows && j>=0) {
            if(binaryMatrix.get(i, j)==0)
                i++;
            else
                j--;
        };
        if(j==cols-1)
            return -1;
        else
            return j+1;
    }
};