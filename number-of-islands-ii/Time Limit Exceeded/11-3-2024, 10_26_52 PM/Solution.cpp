// https://leetcode.com/problems/number-of-islands-ii

class Solution {
private:
    vector<int> roots;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
    int findRoot(int idx) {
        while(idx != roots[idx]) {
            roots[idx] = roots[ roots[idx] ];
        }
        return idx;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        if(m<=0 || n<=0)
            return res;
        roots = vector<int>(m*n, -1);
        int numIsland = 0;
        for(auto pos:positions) {
            int x = pos[0];
            int y = pos[1];
            int idx_p = x*n + y;
            roots[idx_p] = idx_p;
            numIsland++;
            for(auto dir:dirs) {
                int row = x+dir.first;
                int col = y+dir.second;
                int idx_new = row*n+col;
                if(row<0 || row>=m || col <0 || col >=n || roots[idx_new] == -1)
                    continue;
                int rootNew = findRoot(idx_new);
                int rootPos = findRoot(idx_p);
                if(rootPos != rootNew) {
                    roots[rootPos] = rootNew;
                    numIsland--;
                }
            }
            res.push_back(numIsland);
        }
        return res;
    }
};