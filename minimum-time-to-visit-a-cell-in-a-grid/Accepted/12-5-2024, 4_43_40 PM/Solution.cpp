// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0]>1)
            return -1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; //min
        pq.push({0, 0, 0}); //{t, r, c}
        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int t = curr[0];
            int r = curr[1];
            int c = curr[2];
            if(r == rows-1 && c==cols-1 )
                return t;
            if(visited[r][c])
                continue;
            visited[r][c] = true;
            for(auto dir:dirs) {
                int nr = r+dir[0];
                int nc = c+dir[1];
                if(nr<0 || nc<0 || nr>=rows || nc>=cols)
                    continue;
                if(visited[nr][nc])
                    continue;
                int wait = (grid[nr][nc]-t)%2 == 0? 1: 0;
                int nt = max(grid[nr][nc]+wait, t+1);
                pq.push({nt, nr, nc});    
            }
        }
        return -1;
    }
};