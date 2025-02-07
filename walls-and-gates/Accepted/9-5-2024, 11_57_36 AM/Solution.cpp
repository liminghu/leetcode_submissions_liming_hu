// https://leetcode.com/problems/walls-and-gates

/*You are given an m x n grid rooms initialized with these three possible values.
-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to 
represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. 
If it is impossible to reach a gate, it should be filled with INF.
m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 231 - 1.
*/

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int EMPTY = 2147483647;
        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
        int m = rooms.size();
        int n = rooms[0].size();
        // -1: wall, 0: gate, INT_MAX: empty.
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n,0));
        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(rooms[i][j] == 0)  { //0: gate,
                    q.push({i,j});
                    count++;
                    visited[i][j] = count;
                    while(!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for(auto dir:dirs) {
                            int new_i = cur.first+dir.first;
                            int new_j = cur.second+dir.second;
                            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && rooms[new_i][new_j]!=-1 && rooms[new_i][new_j]!=0 && visited[new_i][new_j] < count) { //neither gate nor wall.
                                rooms[new_i][new_j] = min(rooms[new_i][new_j], rooms[cur.first][cur.second]+1);
                                visited[new_i][new_j] = count;
                                q.push({new_i, new_j});
                            }     
                        }
                    }
                }
            }
        }
    }
};