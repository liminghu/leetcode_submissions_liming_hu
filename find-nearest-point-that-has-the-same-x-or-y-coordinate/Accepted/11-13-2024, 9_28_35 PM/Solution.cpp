// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int idx = -1;
        int min_dist = INT_MAX;
        int n = points.size();
        for(int i=0; i<n; i++) {
            int cx = points[i][0];
            int cy = points[i][1];
            if(cx == x || cy == y) {
                int dist = abs(cx-x)+abs(cy-y);
                if(dist < min_dist) {
                    min_dist = dist;
                    idx = i;
                };
            }
        }
        return idx;
    }
};