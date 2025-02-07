// https://leetcode.com/problems/search-a-2d-matrix

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/
class Solution {
private:
    int m = 0;
    int n = 0;
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        if(m==0)
            return false;
        n = matrix[0].size(); //column
        int left = 0;
        int right = m*n-1;
        int pivotIdx = 0;
        int pivotVal = 0;
        while(left <=right) {
            pivotIdx = (left+right)/2;
            int row = pivotIdx / n;
            int col = pivotIdx % n;
            pivotVal = matrix[row][col];
            if(target == pivotVal)
                return true;
            else if(target < pivotVal)
                right = pivotIdx-1;
            else
                left = pivotIdx+1;
        }
        return false;
 
    }
};