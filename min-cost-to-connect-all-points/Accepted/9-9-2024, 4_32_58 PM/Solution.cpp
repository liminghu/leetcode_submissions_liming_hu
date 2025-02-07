// https://leetcode.com/problems/min-cost-to-connect-all-points

/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/
class Solution {
public:
    int Father[1000];
    int findFather(int x) {
        if(Father[x] != x ) {
            Father[x] = findFather(Father[x]);
        };
        return Father[x];
    }
    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if(x < y ) 
            Father[y] = x;
        else
            Father[x] = y;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //Kruskal
        int n = points.size();
        for(int i=0; i<n; i++) {
            Father[i] = i;
        }

        priority_queue<array<int,3>, vector<array<int,3>>,greater<array<int,3>>> edges;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0]-points[j][0]) +  abs(points[i][1]-points[j][1]);
                edges.push({dist, i, j});
            }
        }    
        int result = 0;
        int count = 1;
        while(count < n) { // n-1 edges. n points.
            auto edge = edges.top();
            edges.pop();
            int s = edge[1];
            int t = edge[2];
            int dist = edge[0];
            if(findFather(s)!= findFather(t)) {
                Union(s,t);
                count++;
                result += dist;
                if(count == n)
                    break;
            }
        }
        return result;
    }
};