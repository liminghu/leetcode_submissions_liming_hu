// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        //(0, 0)   (m-1, n-1);
        vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0,1}}; //up, down, left, or right
        vector<vector<int>> objs(m, vector<int>(n, INT_MAX)); //seen[x][y]: min obstacles to reach (x, y)
        queue<tuple<int,int,int>> q; //(x, y, obj)
        int steps = 0;
        q.push({0,0,0});
        objs[0][0] = 0;
        while( !q.empty() ) {
            int sz = q.size();
            while(sz--) {
                int cur_x, cur_y, cur_obj;
                tie(cur_x,cur_y,cur_obj) = q.front(); //tie is a function that creates a tuple of lvalue references
                q.pop();
                if(cur_x==m-1 && cur_y == n-1)
                    return steps;
                for(auto dir:dirs) {
                    int x = cur_x + dir.first;
                    int y = cur_y + dir.second;
                    if(x<0 || x>=m || y<0 || y>=n)
                        continue;
                    int obj = cur_obj + grid[x][y]; //grid[x][y] =0, 1
                    if( obj >= objs[x][y] || obj > k)
                        continue;
                    objs[x][y] = obj;
                    q.push({x,y, obj});
                }
            }
            steps++;
        }
        return -1;
    }
};