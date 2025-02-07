// https://leetcode.com/problems/shortest-path-in-binary-matrix

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {  //bfs
        int sz = grid.size(); 
        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1} };
        vector<vector<bool>> visited(sz, vector<bool>(sz, false));
        int path_len = 0;
        stack< pair<int, int> > q;
        pair<int, int> start = { 0,0 };

        if( grid[start.first][start.second] != 0 ) 
            return -1;

        q.push(start);
        //visited[start.first][start.second] = true;
        
        while(!q.empty()) {
            pair<int, int> current = q.top();
            q.pop();
            visited[current.first][current.second] = true;
            path_len++;

            if(current.first == grid.size()-1 && current.second == grid[0].size()-1) {
                if( grid[current.first][current.second] != 0 ) 
                    return -1; 
                else
                    return path_len-1;
            };
                
            for( int i=0; i < directions.size(); i++ ) {
                if (current.first+directions[i][0] >= 0 && current.first+directions[i][0] < grid.size() && current.second+directions[i][1] >= 0 && current.second+directions[i][1] < grid.size()) {
                    if( !visited[ current.first + directions[i][0] ][ current.second + directions[i][1] ]  && grid [ current.first + directions[i][0] ][ current.second + directions[i][1] ] == 0 ) {
                        q.push( make_pair( current.first+directions[i][0], current.second+directions[i][1] ) );
                    }
                }
            } //for directions
        } //while queue

        return -1;
    }
};