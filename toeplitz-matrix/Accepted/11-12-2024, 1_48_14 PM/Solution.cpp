// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int, int> mp; //key:row-col, value: val
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(mp.find(r-c)==mp.end())
                    mp[r-c] = matrix[r][c];
                else {
                    if(mp[r-c] != matrix[r][c])
                        return false;
                }
            }
        }
        return true;
    }
};