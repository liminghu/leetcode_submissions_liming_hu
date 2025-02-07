// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) { //1 <= m, n <= 50
        //bfs
        // if visited, marked it as -1;
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> bfs_q;
        int max_area = 0;
        int cur_area = 0; 
        for(int i=0; i<rows; i++) {
             for(int j=0; j<cols; j++) {
                 if(grid[i][j] == 1) {
                     //push all the negibors to the queue.
                     bfs_q.push(pair{i,j});
                     grid[i][j] = -1;
                     cur_area = 0;
                     while(!bfs_q.empty()) {
                         pair<int, int> cur = bfs_q.front();
                         bfs_q.pop();                         
                         grid[cur.first][cur.second] = -1;
                         cur_area++;
                         if(cur.first-1>=0 && grid[cur.first-1][cur.second] == 1) {//up
                            bfs_q.push(pair{cur.first-1,cur.second});
                         }
                         if(cur.first+1<rows && grid[cur.first+1][cur.second] == 1) {//down
                            bfs_q.push(pair{cur.first+1,cur.second});
                         }
                         if(cur.second-1>=0 && grid[cur.first][cur.second-1] == 1) {//left
                            bfs_q.push(pair{cur.first,cur.second-1});
                         }
                         if(cur.second+1<cols && grid[cur.first][cur.second+1] == 1) {//right
                            bfs_q.push(pair{cur.first,cur.second+1});
                         }
                     }
                     if(cur_area>max_area)
                         max_area = cur_area;
                 }
                 
             }
            
        }
        return max_area;
        
    }
};