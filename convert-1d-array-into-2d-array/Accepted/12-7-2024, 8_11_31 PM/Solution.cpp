// https://leetcode.com/problems/convert-1d-array-into-2d-array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         if(original.size() != m*n)
            return {};
         vector<vector<int>> rets(m, vector<int>(n,0));
         int i=0;
         while(i<original.size()) {
            int row = i/n;
            int col = i%n;
            rets[row][col] = original[i];
            i++;
         }
         return rets;
    }
};