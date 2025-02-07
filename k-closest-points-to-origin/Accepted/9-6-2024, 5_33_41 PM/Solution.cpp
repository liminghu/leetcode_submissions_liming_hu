// https://leetcode.com/problems/k-closest-points-to-origin

/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
1 <= k <= points.length <= 104
-104 <= xi, yi <= 104
*/
struct dist_coord {
        int distance;
        int x;
        int y;
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto greater_cmp = [](dist_coord a, dist_coord b) {return a.distance > b.distance;};

        priority_queue<dist_coord, vector<dist_coord>, decltype(greater_cmp)> min_pq; //min, distance, {x,y}
        if(k>=points.size())
            return points;

        for(int i=0; i<points.size(); i++) {
            int distance = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            dist_coord d_c;
            d_c.distance = distance;
            d_c.x = points[i][0];
            d_c.y = points[i][1];
            min_pq.push( d_c );
        };
        vector<vector<int>> res;
        for(int i=0; i<k; i++) {
            dist_coord top = min_pq.top();
            min_pq.pop();
            res.push_back({top.x, top.y});
        }  
        return res;      
    }
};