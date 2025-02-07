// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    /*
    Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/
 
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int sz = mat.size();
        
        for(int i=0; i<sz; i++) {
            sum += mat[i][i]+mat[sz-i-1][i];
        };
        
        if(sz%2 == 1)
            sum -= mat[sz/2][sz/2];
        
        return sum;
    }
};