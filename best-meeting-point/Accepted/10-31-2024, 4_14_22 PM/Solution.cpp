// https://leetcode.com/problems/best-meeting-point

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(); //rows.
        int n = grid[0].size(); //columns
        vector<int> row_sum(n, 0);
        vector<int> col_num(m, 0);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                row_sum[j] += grid[i][j];
                col_num[i] += grid[i][j];
            };
        };

        return minDistance1D(row_sum) + minDistance1D(col_num);
    }
    int minDistance1D(vector<int>& nums) {
        int i = -1;
        int j = nums.size();
        int d = 0;
        int left = 0;
        int right = 0;
        while( i != j ) {
            if(left < right) {
                 d += left;
                 i++;
                 left += nums[i];
            } else {
                d += right;
                j--;
                right += nums[j];
            }
        }
        return d;
    }
};