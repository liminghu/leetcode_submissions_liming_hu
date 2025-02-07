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
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int rows = dims[0];
        int cols = dims[1];
        int curCol = cols-1;
        for(int i=0; i<rows; i++) {
            while(curCol>=0 && binaryMatrix.get(i, curCol)==1)
                curCol--;
        };
        return curCol==cols-1? -1: curCol+1;
    }
};