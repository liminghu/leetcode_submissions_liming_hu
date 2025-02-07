// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		if(grid.empty()) return 0;
		int m = grid.size(); //row
		int n = grid[0].size(); //column.
		
		int ans = 0;
		for(int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans += grid[i][j] - '0';
				dfs(grid, i, j, m, n);
			}
		}
		return ans;
    }
private:
	void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
		if( i<0 || j <0 || i>=m || j >=n || grid[i][j] == '0')
			return;
		grid[i][j] = '0'; //visited or '0' by itself.
		dfs(grid, i-1, j, m, n);
		dfs(grid, i+1, j, m, n);
		dfs(grid, i, j-1, m, n);
		dfs(grid, i, j+1, m, n);
	}
};