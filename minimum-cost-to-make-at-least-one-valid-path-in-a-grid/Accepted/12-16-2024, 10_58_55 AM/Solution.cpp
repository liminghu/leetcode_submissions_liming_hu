// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid

class Solution {
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minCost(vector<vector<int>>& grid) {
        /*
        1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
        2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
        3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
        4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
        */
        int m = grid.size();
        int n = grid[0].size();
       int res  = m + n - 2;
       vector<vector<int>> cost(m, vector<int>(n, m+n-2));
       cost[0][0] = 0;
       queue<pair<int, int>> q;
       q.push({0, 0});      
       while(!q.empty()) {
            pair<int, int> t = q.front();
            int i = t.first;
            int j = t.second;
            q.pop();
            if(i==m-1 && j==n-1) {
                res = min(res, cost[i][j]);
            }
            for(int k=0; k<4; k++) {
                int new_i = i+dirs[k].first;
                int new_j = j+dirs[k].second;
                int curCost = grid[i][j]==k+1? cost[i][j]:(cost[i][j]+1);
                if(new_i<0|| new_i>=m || new_j<0 || new_j>=n|| curCost>=cost[new_i][new_j] || curCost>=res)
                    continue;
                cost[new_i][new_j] = curCost;
                q.push({new_i, new_j});
            }
       }
       return res;  
    }
};