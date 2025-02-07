// https://leetcode.com/problems/equal-row-and-column-pairs

/*
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> mp;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++) {
            //rows. grid[i][...]
            string s_key = "";
            for(int j=0; j<n; j++)
                s_key.push_back(grid[i][j]+'0');
            mp[s_key]++;
        }
        int ret = 0;
        for(int j=0; j<n; j++) {
            //rows. grid[i][...]
            string s_key = "";
            for(int i=0; i<m; i++)
                s_key.push_back(grid[i][j]+'0');
            if(mp.find(s_key)!=mp.end()) {
                ret = ret + mp[s_key];
            }
        }
        return ret;
    }
};