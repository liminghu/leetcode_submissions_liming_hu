// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        //0: land
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0 || visited[i][j])
                    continue;
                int fish = 0;
                queue<pair<int,int>> q;
                visited[i][j] = true;
                q.push({i, j});
                while(!q.empty()) {
                    int curi = q.front().first;
                    int curj = q.front().second;
                    fish += grid[curi][curj];
                    q.pop(); 
                    for(auto dir: dirs) {
                        int newi = curi + dir.first;
                        int newj = curj + dir.second;
                        if(newi<0 || newi>=m || newj<0 || newj >= n || grid[newi][newj]==0 || visited[newi][newj])
                            continue;
                        q.push({newi, newj});
                        visited[newi][newj] = true;
                    }
                }
                ret = max(ret, fish);
            }
        }
        return ret;
    }
};