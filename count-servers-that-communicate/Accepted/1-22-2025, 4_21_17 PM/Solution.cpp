// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {// 1 means that on that cell there is a server and 0 means that it is no server
        int m = grid.size();
        int n = grid[0].size();
        //Return the number of servers that communicate with any other server.
        int ret = 0;
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    if(rows[i]>1 || cols[j]>1) 
                        ret++;
                }
            }
        }
        return ret;
    }
};