// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //bfs
        int rows = grid.size();
        int cols = grid[0].size();
        
        int ans = 0;        
        queue<pair<int,int>> qe;
        
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    qe.push({i,j});
                    grid[i][j] = ans;
                    while(!qe.empty()) {
                        pair<int,int> cur = qe.front();
                        qe.pop();
                        if(cur.first+1<rows && grid[cur.first+1][cur.second] == '1') { //down
                            qe.push({cur.first+1,cur.second});
                            grid[cur.first+1][cur.second] = ans;
                        }
                        if(cur.second+1<cols && grid[cur.first][cur.second+1] == '1') {
                            qe.push({cur.first,cur.second+1});
                            grid[cur.first][cur.second+1] = ans;
                        }
                        if(cur.first-1>0 && grid[cur.first-1][cur.second] == '1') {
                            qe.push({cur.first-1,cur.second});
                            grid[cur.first-1][cur.second] = ans;
                        }
                        if(cur.second-1>0 && grid[cur.first][cur.second-1] == '1') {
                            qe.push({cur.first,cur.second-1});
                            grid[cur.first][cur.second-1] = ans;
                        }
                         
                    }
                }
            }
            
        }
        return ans;
        
    }
};