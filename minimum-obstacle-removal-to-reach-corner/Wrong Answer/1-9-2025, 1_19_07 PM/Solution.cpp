// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> obstacles(m, vector<int>(n, INT_MAX));
        obstacles[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //min heap: obstacles, x, y
        pq.push({obstacles[0][0], 0, 0});
        while(!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            int obs = t[0], x = t[1], y = t[2];
            if(x=m-1 && y == n-1)
                return obs;
            for(vector<int>& dir: dirs) {
                int nx = x+dir[0], ny = y+dir[1];
                if(nx<0 || ny <0 || nx>=m || ny>=n)
                    continue;
                int newobs = obs + grid[nx][ny];
                if(newobs < obstacles[nx][ny]) {
                    obstacles[nx][ny] = newobs;
                    pq.push({newobs, nx, ny});
                }
            }
        }
        return obstacles[m-1][n-1];
    }
};