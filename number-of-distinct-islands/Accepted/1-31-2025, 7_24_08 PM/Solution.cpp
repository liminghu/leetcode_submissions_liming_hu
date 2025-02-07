// https://leetcode.com/problems/number-of-distinct-islands

class Solution {
vector<vector<int>> grid;
vector<vector<bool>> visited;
string curIsland;
public:
    int numDistinctIslands(vector<vector<int>>& grid) { //1 <= m, n <= 50
        this->grid = grid;
        int m = grid.size();
        int n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        unordered_set<string> islands;
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                curIsland = "";
                dfs(r, c, '0');
                if(curIsland.length()==0)
                    continue;
                islands.insert(curIsland);
            }
        }
        return islands.size();
    }
    void dfs(int r, int c, char dir) {
        if(r<0 || c<0 || r>=grid.size() || c >=grid[0].size() || visited[r][c] || grid[r][c]==0)
            return;
        visited[r][c] = true;
        curIsland += dir;
        dfs(r+1, c, 'D');
        dfs(r-1, c, 'U');
        dfs(r, c+1, 'R');
        dfs(r, c-1, 'L');
        curIsland += '0';
    }
};