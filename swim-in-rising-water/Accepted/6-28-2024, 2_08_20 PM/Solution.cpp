// https://leetcode.com/problems/swim-in-rising-water

/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 
4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim 
infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) { //1 <= n <= 50
                                                //0 <= grid[i][j] < n2
                                                //Each value grid[i][j] is unique.

        //Dijkstra
        const int sz = grid.size();
        vector<vector<int>> directions = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1} };
        priority_queue< pair< int, pair<int, int> > > q;  //maximum in the top.    {-time, {row, col}}, negative to get the maximim for the priority queue.
        q.push({-grid[0][0], pair{0,0}});
        vector<vector<int>> seen(sz, vector<int>(sz,0));
        seen[0][0] = 1;

        while(!q.empty()) {
            pair<int, pair<int, int>> cur = q.top();
            q.pop();
            int time = -cur.first;
            int row = cur.second.first;
            int col = cur.second.second;
            if( col == sz-1 && row == sz-1 )
                return time;
            
            for(int i=0; i<directions.size(); i++) {
                if( row + directions[i][0] >= 0 && row+directions[i][0]<=sz-1 && col+directions[i][1]>=0 && col+directions[i][1]<=sz-1) {
                    if(seen[ row + directions[i][0] ] [ col + directions[i][1] ])
                        continue;
                    seen[ row + directions[i][0] ] [ col + directions[i][1] ] = 1;
                    q.push(pair{ -max(time, grid[ row + directions[i][0] ][ col + directions[i][1] ]), pair{row + directions[i][0], col + directions[i][1]} });
                }
            } 
        }

        return -1;
    }
};