// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    queue<pair<int,int>> q;
    vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    int shortestBridge(vector<vector<int>>& grid) {//n x n binary matrix grid where 1 represents land and 0 represents water.
        int n = grid.size();
        int firstX = -1, firstY = -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if( grid[i][j] == 1) {
                    firstX = i;
                    firstY = j;
                    dfs(grid, firstX, firstY, n);
                    q.push({firstX, firstY});
                    break;
                }
            }
            if(firstX != -1)
                break;
        }

        return bfs(grid, n);
    }
    //Start from grid[first_x][first_y] and use depth-first search to find and set the values of all cells of the same island (island A) to 2.
    void dfs(vector<vector<int>>& grid, int x, int y, int n) {
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y] == 0 || grid[x][y] == 2)
            return;
        grid[x][y] = 2; //visited.
        q.push({x,y});
        dfs(grid, x+1, y,   n);
        dfs(grid, x-1, y,   n);
        dfs(grid, x,   y+1, n);
        dfs(grid, x,   y-1, n);
    }
    int bfs(vector<vector<int>>& grid, int n) {
        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz-->0) {
                auto cur = q.front();
                q.pop();
                for(auto dir: dirs) {
                    int newX = cur.first + dir.first;
                    int newY = cur.second + dir.second;
                    if(newX<0 || newX>=n || newY <0 || newY>=n || grid[newX][newY]==2)
                        continue;
                    if(grid[newX][newY] == 1)
                        return d;
                    else if (grid[newX][newY] == 0) {
                        q.push({newX, newY}); 
                        grid[newX][newY] = 2; //visited..
                    }
                } 
            }
            d++; // increasing each level by distance + 1
        }
        return d;
    }
};