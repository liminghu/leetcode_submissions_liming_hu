// https://leetcode.com/problems/pacific-atlantic-water-flow

/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the 
island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights 
where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, 
south, east, and west if the neighboring cell's height is less than or equal to the current cell's 
height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow
 from cell (ri, ci) to both the Pacific and Atlantic oceans.
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105
 */
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //heights[r][c]: height above sea level

        //Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow 
        //from cell (ri, ci) to both the Pacific and Atlantic oceans.
        if(heights.empty())
            return {};
        vector<vector<int>> p(n, vector<int>(m,0)); //pacific.
        vector<vector<int>> a(n, vector<int>(m,0)); //atlantic.
        for(int x=0; x<m; x++) {
            dfs(heights, x, 0, 0, p); //top. 0: current max height.   y:0
            dfs(heights, x, n-1, 0, a); //bottom     y:n-1
        }
        for(int y=0; y<n; y++) {
            dfs(heights, 0, y, 0, p); //left. 0: current max height. x:0
            dfs(heights, m-1, y, 0, a); //right             x:m-1
        }        
        vector<vector<int>> ans;
        for(int x=0; x<m; x++) {
            for(int y=0; y<n; y++) {
                if(p[y][x] && a[y][x] )
                    ans.push_back({y, x}); //y: row. x:col.
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& heights, int x, int y, int h, vector<vector<int>> & v) {
        if(x<0 || y<0 || x == heights[0].size() || y == heights.size())
            return;
        if(v[y][x] || heights[y][x] < h) //visited before, or its height not enough. 
            return;
        v[y][x] = true;
        dfs(heights, x+1, y, heights[y][x], v); //new height: heights[y][x].
        dfs(heights, x-1, y, heights[y][x], v); //new height: heights[y][x].
        dfs(heights, x, y+1, heights[y][x], v); //new height: heights[y][x].
        dfs(heights, x, y-1, heights[y][x], v); //new height: heights[y][x].                
    }
};