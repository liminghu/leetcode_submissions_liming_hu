// https://leetcode.com/problems/range-sum-query-2d-mutable

/*
Given a 2D matrix matrix, handle multiple queries of the following types:

Update the value of a cell in matrix.
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
void update(int row, int col, int val) Updates the value of matrix[row][col] to be val.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left 
corner (row1, col1) and lower right corner (row2, col2).
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-1000 <= matrix[i][j] <= 1000
0 <= row < m
0 <= col < n
-1000 <= val <= 1000
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 5000 calls will be made to sumRegion and update.
*/
class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> presum;
    int m, n;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        presum = vector(m, vector(n,0));
        this->m = m;
        this->n = n;

        presum[0][0] = matrix[0][0];
        for(int j=1; j<n; j++)
            presum[0][0] =  presum[0][j-1] + matrix[0][j];
        for(int i=1; i<m; i++)
            presum[i][0] = presum[i-1][0] + matrix[i][0];

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                presum[i][j] = presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    void update(int row, int col, int val) { //Update the value of a cell in matrix.
        int prev_val = matrix[row][col];
        matrix[row][col] = val;
        int diff = val-prev_val;

        for(int i=row; i<m; i++) {
            for(int j=col; j<n; j++) {
                presum[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { //Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
        if (row1 >=1 && col1 >=1 ) {
            return presum[row2][col2] + presum[row1-1][col1-1] - presum[row2][col1-1]-presum[row1-1][col2];
        };
        if(row1 == 0 && col1 == 0) {
            return presum[row2][col2];
        }

        if(row1 == 0 && col1 >0 ) {
            return presum[row2][col2] - presum[row2][col1-1];
        }
        if(row1 > 0 && col1 == 0 ) {
            return presum[row2][col2] - presum[row1-1][col2];
        }
        return 0;
    };
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */