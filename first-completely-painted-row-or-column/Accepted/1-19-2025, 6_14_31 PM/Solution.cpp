// https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //Return the smallest index i at which either a row or a column will be completely painted in mat.
        unordered_map<int, int> mpr, mpc;
        unordered_map<int, int> mprc, mpcc;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mpr[mat[i][j]] = i;
                mpc[mat[i][j]] = j;
            }
        }
        for(int i=0; i<arr.size(); i++) {
            int num = arr[i];
            mprc[mpr[num]]++;
            mpcc[mpc[num]]++;
            if(mprc[mpr[num]]==n || mpcc[mpc[num]] == m)
                return i;
        }
        return -1;
    }
};