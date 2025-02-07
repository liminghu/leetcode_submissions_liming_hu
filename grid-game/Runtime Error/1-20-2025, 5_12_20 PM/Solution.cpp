// https://leetcode.com/problems/grid-game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0);
        long long bottom = 0;
        long long res = LLONG_MAX;
        /*Since the robots cannot go up, we need to find the best point i for the first robot to go down.
          For the second robot, we only have two choices - go down right away, or stay up till the end.
          For a point i, the second robot can either collect bottom = sum(grid[1][0] .. grid[1][i - 1]) if it goes down, or top = sum(grid[0][i + 1] ... grid[0][n - 1]) otherwise.
          We can compute those values using prefix/suffix sum in O(1), and then find the minimum of max(top, bottom).
        */
        for(int i=0; i<n; i++) { //suppose the first robot go down at i.
            top -= grid[0][i];   //For a point i, the second robot can either collect bottom = sum(grid[1][0] .. grid[1][i - 1]), if the first robot goes down
            res = min(res, max(top, bottom));
            bottom += grid[1][i];
        }
        return res;
    }
};