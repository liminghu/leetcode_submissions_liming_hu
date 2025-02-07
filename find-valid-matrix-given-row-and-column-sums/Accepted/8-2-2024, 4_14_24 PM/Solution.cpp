// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

/*
You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and 
colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, 
but you do know the sums of each row and column.
Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that 
fulfills the requirements exists.
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
       /*
        1 <= rowSum.length, colSum.length <= 500
        0 <= rowSum[i], colSum[i] <= 108
        sum(rowSum) == sum(colSum)
        */
        //Find the smallest rowSum or colSum, and let it be x. 
        //Place that number in the grid, and subtract x from rowSum and colSum. Continue until all the sums are satisfied.

        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        int minColSum = INT_MAX;
        int col_index = -1;
        for(int j=0; j<cols; j++) {
            if(colSum[j] < minColSum && colSum[j] > 0) {
                minColSum = colSum[j];
                col_index = j;
            }
        }
 
        int minRowSum = INT_MAX;
        int row_index = -1;
        for(int i=0; i<rows; i++) {
            if(rowSum[i] < minRowSum && rowSum[i] > 0) {
                minRowSum = rowSum[i];
                row_index = i;
            }
        }

 

        while(minRowSum != INT_MAX || minColSum != INT_MAX) {
            if(row_index >=0 && col_index >=0) {
                matrix[row_index][col_index] = min(minColSum, minRowSum);
                rowSum[row_index] -= min(minColSum, minRowSum);
                colSum[col_index] -= min(minColSum, minRowSum);
            }

            minColSum = INT_MAX;
            for(int j=0; j<cols; j++) {
                if(colSum[j] < minColSum && colSum[j] > 0) {
                    minColSum = colSum[j];
                    col_index = j;
                }
            }

            minRowSum = INT_MAX;
            for(int i=0; i<rows; i++) {
                if(rowSum[i] < minRowSum && rowSum[i] > 0) {
                    minRowSum = rowSum[i];
                    row_index = i;
                }
            }
        }
        return matrix;
    }
};