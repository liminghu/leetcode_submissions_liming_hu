// https://leetcode.com/problems/trapping-rain-water-ii

typedef vector<int> VI;
class Solution { //BFS+priority_queue: Dijkstra.
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<VI, vector<VI>, greater<>> pq;
        auto visited = vector<vector<int>>(m, vector<int>(n,0));
        auto dirs = vector<pair<int,int>>( { {1,0},{-1,0},{0,1},{0,-1} } );
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0|| i==m-1|| j==0 || j==n-1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int ret = 0;
        int cur_height = INT_MIN;
        while(!pq.empty()) {
            int h = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if(h>cur_height)
                cur_height = h;
            ret += cur_height-h;
            for(int k=0; k<4; k++) {
                int i=x+dirs[k].first;
                int j=y+dirs[k].second;
                if(i<0 || i>=m || j<0 || j>=n)
                    continue;
                if(visited[i][j])
                    continue;
                visited[i][j] = 1;
                pq.push({heightMap[i][j], i, j});
            }
        }
        return ret;
    }
};