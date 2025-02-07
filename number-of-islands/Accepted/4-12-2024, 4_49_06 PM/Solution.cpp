// https://leetcode.com/problems/number-of-islands

class Solution {
private:
    void bfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        int m = grid.size();    //rows
        int n = grid[0].size();  //columns
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0, -1}, {0,1}};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto dir: directions) {
                int nRow = dir.first + r;
                int nCol = dir.second + c;
                if(nRow>=0 && nRow < m && nCol >=0 && nCol < n && !visited[nRow][nCol] && grid[nRow][nCol] == '1') {
                    visited[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) { //we will update grid for status: -1: visited.
        int m = grid.size();    //rows
        int n = grid[0].size();  //columns
        int num = 0;

        //DFS
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) { //land
                    grid[i][j] = -1; //mark it as visited.
                    num = num+1;  //find a new island.
                    bfs(i, j, visited, grid);
                }       
            }
        }
        return num;
    }
};