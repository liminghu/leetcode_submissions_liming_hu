// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

/*
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). 
You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column 
of the cell you are initially standing at.
In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot 
step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell 
that is at the border of the maze. The entrance does not count as an exit.
Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
maze.length == m
maze[i].length == n
1 <= m, n <= 100
maze[i][j] is either '.' or '+'.
entrance.length == 2
0 <= entrancerow < m
0 <= entrancecol < n
entrance will always be an empty cell.
*/
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<array<int,3>> q;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ret = 0;
        q.push({entrance[0], entrance[1], 0}); //r, c, steps.
        visited[entrance[0]][entrance[1]] = 1;
        while( !q.empty() ) {
            array<int,3> f = q.front();
            q.pop();
            for( int i = 0; i < dirs.size(); i++ ) {
                int nb_r = f[0]  + dirs[i][0];
                int nb_c = f[1]  + dirs[i][1];
                if( nb_r >= 0 && nb_c >= 0 && nb_r <= m-1 && nb_c <= n-1 && visited[nb_r][nb_c] == 0 && maze[nb_r][nb_c] == '.') {
                    if(isBorder(nb_r, nb_c, m, n))
                        return f[2]+1;
                    q.push({nb_r, nb_c, f[2]+1});
                    visited[nb_r][nb_c] = 1;
                }
            }
        };
        return -1;
    }

    bool isBorder(int i, int j, int m, int n) {
        if( i == 0 || j == 0 || i == m-1 || j == n-1)
            return true;
        else
            return false;
    }
};