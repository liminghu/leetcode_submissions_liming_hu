// https://leetcode.com/problems/making-a-large-island

/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.
*/
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        /*  n == grid.length
            n == grid[i].length
            1 <= n <= 500
            grid[i][j] is either 0 or 1.
        */
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int numIslands = 0;
        unordered_map<int, int> mp; //num_islands, size
        mp[-1] = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && visited[i][j] == -1) {
                    int size = 1;
                    visited[i][j] = numIslands;
                    q.push(make_pair(i, j));
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for(int k=0; k<dirs.size(); k++) {
                            long neighbor_i = cur.first + dirs[k].first;
                            long neighbor_j = cur.second + dirs[k].second;
                            if( (neighbor_i >= 0 && neighbor_i < n && neighbor_j >= 0 && neighbor_j < n) && grid[neighbor_i][neighbor_j] == 1 && visited[neighbor_i][neighbor_j] == -1) {
                                q.push( make_pair(neighbor_i, neighbor_j) );
                                visited[ neighbor_i ][ neighbor_j ] = numIslands;
                                size++;
                            };
                        };
                    };
                    mp[numIslands] = size;
                    numIslands++;
                };
            };
        };

         int res = -1;
         for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0 && visited[i][j] == -1) { //the land can be changed.
                    int numIsland = visited[i][j]; //-1
                    int size = mp[numIsland]; //1
                    res = max(res, mp[numIsland]);

                    int sizeNeib = 0;
                    unordered_set<int> s;
                    for(auto dir:dirs) { //find its four neighbors.
                        if(i+dir.first>=0 && i+dir.first<n && j+dir.second>=0 && j+dir.second<n && visited[i+dir.first][j+dir.second] != -1) {
                            int neinumIsland = visited[i+dir.first][j+dir.second]; 
                            if(!s.contains(neinumIsland)) {
                                s.insert(neinumIsland);                         
                                sizeNeib += mp[neinumIsland];
                           }
                        };
                    };
                    res = max(res, mp[numIsland]+sizeNeib);                
                } else { //no land changed.
                    if(grid[i][j] == 1) {
                        int numIsland = visited[i][j]; 
                        int size = mp[numIsland]; 
                        res = max(res, size);
                    };
                }
            }
         }
         return res;       
    }
};