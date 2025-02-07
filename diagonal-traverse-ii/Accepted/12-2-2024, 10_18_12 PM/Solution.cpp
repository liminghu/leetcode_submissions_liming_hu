// https://leetcode.com/problems/diagonal-traverse-ii

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<int> rets;
        unordered_map<int, vector<int>> matrix;
        int matKey = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<nums[i].size(); j++) {
                matrix[i+j].push_back(nums[i][j]);
                matKey = max(matKey, i+j);
            }
        }
        for(int i=0; i<=matKey; i++) {
            //diagonals are from bottom to top, but we traversed the input matrix from first row to last row. 
            //Hence we need to print the elements in reverse order.
            for(auto x=matrix[i].rbegin(); x!=matrix[i].rend(); x++)
                rets.push_back(*x);
        }
        return rets;
    }
};