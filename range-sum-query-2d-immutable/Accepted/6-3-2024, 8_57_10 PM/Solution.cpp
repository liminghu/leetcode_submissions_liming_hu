// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
private:
    vector<vector<int>> myMatrix;
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        myMatrix = vector<vector<int>>(rows, vector<int>(cols,0));
        myMatrix = matrix;
        sum = vector<vector<int>>(rows, vector<int>(cols,0));

        int i=0; sum[0][0] = myMatrix[0][0];
        for(int j=1; j<cols; j++) {   //first row.
            sum[0][j] = sum[0][j-1]+myMatrix[0][j];
        };   
        for(int i=1; i<rows; i++) {   //first col
            sum[i][0] = sum[i-1][0]+myMatrix[i][0];
        };   

        for(int i=1; i<rows; i++) {
            for(int j=1; j<cols; j++) {
                sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+myMatrix[i][j];
            }        
        }


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { //You must design an algorithm where sumRegion works on O(1) time complexity.
        int ans=0;
        if(row1>=1 && col1 >=1) {
            ans = sum[row2][col2]+sum[row1-1][col1-1]-sum[row2][col1-1]-sum[row1-1][col2];
        } else if(row1==0 && col1 >=1) {
            ans = sum[row2][col2]-sum[row2][col1-1];
        } else if(row1>=1 && col1 ==0) {
            ans = sum[row2][col2]-sum[row1-1][col2];
        }else { //rows == 0; col1==0
            ans = sum[row2][col2];
        }
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */