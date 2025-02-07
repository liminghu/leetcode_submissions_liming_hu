// https://leetcode.com/problems/lucky-numbers-in-a-matrix

/*
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
         /*
            m == mat.length
            n == mat[i].length
            1 <= n, m <= 50
            1 <= matrix[i][j] <= 105.
            All elements in the matrix are distinct.
        */
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minMax;
        for(int i=0; i<m; i++) {
            int minEle = INT_MAX;
            int idx_col = -1;
            for(int j=0; j<n; j++) {
                if(matrix[i][j] < minEle) {
                    minEle = matrix[i][j];
                    idx_col = j;
                }
            };
            // idx_col column.
            int count = 0;
            for(int k=0; k<m; k++) {
                if(matrix[k][idx_col] > minEle)
                    break;
                else
                    count++;
            }
            if(count == m )
                minMax.push_back(minEle);
        }
        return minMax;
    }
};