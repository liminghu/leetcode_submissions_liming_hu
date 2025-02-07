// https://leetcode.com/problems/find-missing-and-repeated-values

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> visited(n*n+1, 0); //50*50+1
        int first = 0;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(visited[ grid[i][j] ] == 1) 
                    first = grid[i][j];
                sum += grid[i][j];
                visited[grid[i][j]] = 1;
            }
        }
        long long second = (n*n)*(n*n+1)/2 - (sum-first);
        return {first, (int)second};
    }
};