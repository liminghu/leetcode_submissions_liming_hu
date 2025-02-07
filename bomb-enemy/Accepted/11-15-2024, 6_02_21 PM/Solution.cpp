// https://leetcode.com/problems/bomb-enemy

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '0') {
                    int numBomb = bomb(i, j, grid);
                    res = max(res, numBomb);
                }
            }
        }
        return res;
    }
    int bomb(int i, int j, vector<vector<char>>& grid) {
        int count = 0;
        int k = i+1;
        while(k < grid.size() && grid[k][j]!= 'W') {
            if(grid[k][j] == 'E')
                count++;
            k++;
        };
        k = i-1;
        while(k >=0 && grid[k][j]!= 'W') {
            if(grid[k][j] == 'E')
                count++;
            k--;
        };
        k = j+1;
        while(k < grid[i].size() && grid[i][k]!= 'W') {
            if(grid[i][k] == 'E')
                count++;
            k++;
        };
        k = j-1;
        while(k >=0 && grid[i][k]!= 'W') {
            if(grid[i][k] == 'E')
                count++;
            k--;
        };        
        return count;
    }
};