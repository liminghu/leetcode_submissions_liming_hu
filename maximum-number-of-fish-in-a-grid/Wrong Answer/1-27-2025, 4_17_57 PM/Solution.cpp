// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        //0: land
        int ret = -1;
        int m = grid.size();
        int n = grid[0].size();
        cout << "m: " << m << " n: " << n << endl;
        vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==0)
                    continue;
                int fish = 0;
                queue<pair<int,int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    int curi = q.front().first;
                    int curj = q.front().second;
                    fish += grid[curi][curj];
                    grid[curi][curj] = 0;
                    q.pop(); 
                    for(auto dir: directions) {
                        int newi = curi + dir.first;
                        int newj = curj + dir.second;
                        cout << "newi: "<< newi << endl;
                        cout << "newj: "<< newj << endl;
                        if(newi<0 || newi>=m || newj<0 || newj >= n || grid[newi][newj]==0)
                            continue;
                        q.push({newi, newj});
                    }
                }
                ret = max(ret, fish);
            }
        }
        return ret;
    }
};