// https://leetcode.com/problems/the-maze-ii

/*
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, 
left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], 
return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.
The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).
You may assume that the borders of the maze are all walls (see examples).

 Example 1:
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: 12
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2:
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: -1
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.

Example 3:
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: -1
 
Constraints:
m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow < m
0 <= startcol, destinationcol < n
Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.
*/
class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return dijkstra(maze, start, destination);
    }
    int dijkstra(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        auto comp = [](const vector<int> a, const vector<int> b) {return a[0] > b[0];};
        priority_queue< vector<int>, vector<vector<int>>, decltype(comp) > q; //min {distance, x, y}
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

        q.push({0, start[0], start[1]});  
        while( !q.empty() ) {
            vector<int> t = q.top();
            int dist = t[0];
            int  r = t[1];
            int  c = t[2];
            q.pop();

            if(visited[r][c] )
                continue;
            visited[r][c] = true;

            if(r == destination[0] && c == destination[1])
                return dist;

            for(auto dir: dirs) {
                int x = r + dir[0];
                int y = c + dir[1];
                int steps = 0;
                while( x >= 0 && x < maze.size() && 
                       y >= 0 && y < maze[0].size() && 
                       maze[x] [y] == 0) {   //continue in one direction until wall.
                    x += dir[0];
                    y += dir[1];
                    steps++;
                }
                x = x - dir[0]; //back one step, since it is invalid.
                y = y - dir[1];
                if(!visited[x][y]) {
                    vector<int> e(3);
                    e[0] = dist + steps;
                    e[1] = x;
                    e[2] = y;
                    q.push(e);
                }
            };
        }
        return -1; //can not reach.
    }
};
/*class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        dist[start[0]][start[1]] = 0;
        dfs(maze, start, dist);
        return dist[destination[0]][destination[1]]==INT_MAX? -1: dist[destination[0]][destination[1]];
    }
    void dfs(vector<vector<int>>& maze, vector<int>& start, vector<vector<int>>& dist) {
        for(auto dir: dirs) {
            int x = start[0];
            int y = start[1];
            int count = 0;
            while( x+dir[0] >= 0 && x+dir[0] < maze.size() && 
                   y+dir[1] >= 0 && y+dir[1] < maze[0].size() && 
                   maze[x+dir[0]] [y+dir[1]] == 0) {   //continue in one direction until wall.
                    x += dir[0];
                    y += dir[1];
                    count++;
            }
            if(dist [start[0] ][ start[1] ] + count < dist[x][y]) {
                dist[x][y] = dist[ start[0] ][ start[1] ] + count;
                vector<int> new_start(2);
                new_start[0] = x;
                new_start[1] = y;
                dfs(maze, new_start, dist);
            }
        }
    }
};*/