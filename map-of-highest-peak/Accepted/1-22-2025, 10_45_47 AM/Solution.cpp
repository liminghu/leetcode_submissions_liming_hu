// https://leetcode.com/problems/map-of-highest-peak

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        //0: land; 1: water
        vector<pair<int,int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> heights(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(isWater[i][j]) {
                    q.push({i, j});
                    heights[i][j] = 0;
                }
            }
        }
        int heightLayer = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                pair<int, int> cur = q.front();
                q.pop();
                for(auto dir: dirs) {
                    int newX = cur.first + dir.first;
                    int newY = cur.second + dir.second;
                    if(newX>=0 && newX<m && newY>=0 && newY<n && heights[newX][newY]==-1) {
                        heights[newX][newY] = heightLayer;
                        q.push({newX, newY});
                    }
                }
            }
            heightLayer++;
        }
        return heights;
    }
};