// https://leetcode.com/problems/shortest-distance-from-all-buildings

/*
You are given an m x n grid grid of values 0, 1, or 2, where:
each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. 
You can only move up, down, left, and right.
Return the shortest travel distance for such a house. If it is not possible to build such a house according to 
the above rules, return -1.
The total travel distance is the sum of the distances between the houses of the friends and the meeting point.
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0, 1, or 2.
There will be at least one building in the grid.
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {

        int totalHouse = 0;
        int min_dist = INT_MAX;
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) { //house.
                    totalHouse++;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) { //empty
                    int distanceSum = bfs(grid, i, j, totalHouse);
                    min_dist = min(min_dist, distanceSum);
                } //if
            }
        }
        return min_dist == INT_MAX? -1: min_dist;   
    }

    int bfs(vector<vector<int>>& grid, int row, int col, int totalHouse) {
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int m = grid.size(); //row
        int n = grid[0].size(); //col

        vector<vector<int>> visited(m, vector<int>(n,0));
        int distanceSum = 0;
        int housesReached = 0;

        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = 1;
        
        int distance = 0;
        while(!q.empty() && housesReached < totalHouse) {
            int q_size = q.size();
            for(int k=0; k<q_size; k++) {
                auto curr = q.front();
                q.pop();
                if(grid[curr.first][curr.second] == 1) { //building.  building can not pass through: so continue.
                    distanceSum += distance;
                    housesReached++;
                    continue;
                };
                for(auto& dir: dirs) {
                    int nextRow = curr.first + dir[0];
                    int nextCol = curr.second + dir[1];
                    if( nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {//0:empty, 1: house.
                        visited[nextRow][nextCol] = 1;
                        q.push({nextRow,nextCol});
                    }
                }//end for dir
            }//end one layer.
            distance++;
        }
        //if we can not reach all houses, then any cell we visited can not reach all houses. we mark them as obstacle.
        if(housesReached != totalHouse) {
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++) {
                    if(grid[i][j] == 0 && visited[i][j])
                        grid[i][j] = 2;
                }
            }
            return INT_MAX;
        }
        return distanceSum; //if we reach all the houses.
    }  
};