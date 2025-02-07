// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        //(0, 0)   (m-1, n-1);
        vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0,1}}; //up, down, left, or right
        vector<vector<int>> seen(m, vector<int>(n, INT_MAX)); //seen[x][y]: min obstacles to reach (x, y)
        queue<tuple<int,int,int>> q; //(x, y, o)
        int steps = 0;
        q.push({0,0,0});
        seen[0][0] = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cx, cy, co;
                tie(cx,cy,co) = q.front();
                q.pop();
                if(cx==m-1 && cy == n-1)
                    return steps;
                for(auto dir:dirs) {
                    int x = cx + dir.first;
                    int y = cy + dir.second;
                    if(x<0 || x>=m || y<0 || y>=n)
                        continue;
                    int obj = co + grid[x][y];
                    if( obj >= seen[x][y] || obj > k)
                        continue;
                    seen[x][y] = obj;
                    q.push({x,y, obj});
                }
            }
            steps++;
        }
        return -1;
    }
};