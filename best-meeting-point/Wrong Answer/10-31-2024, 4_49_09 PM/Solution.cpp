// https://leetcode.com/problems/best-meeting-point

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(); //rows.
        int n = grid[0].size(); //columns
        vector<int> rows;
        vector<int> cols;
        vector<vector<int>> houses;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    houses.push_back({i,j});
                    rows.push_back(i);
                }
            }
        }
        for(int j=0; j<n; j++) {
            for(int i=0; i<m; i++) {
                if(grid[i][j] == 1) {
                    cols.push_back(j);
                }
            }
        };
        int median_row = rows[rows.size()/2];
        int median_col = rows[cols.size()/2];
        int res = 0;
        for(int i=0; i<houses.size(); i++)
            res += abs(houses[i][0]-median_row) + abs(houses[i][1]-median_col);
        return res;
    }
 /*   int minTotalDistance(vector<vector<int>>& grid) {
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
    }*/
};