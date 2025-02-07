// https://leetcode.com/problems/max-points-on-a-line

//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
/*
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            unordered_map<string, int> count; //key: <py, px> 
            int same_points = 1;
            int max_points = 0;
            const auto& p1 = points[i]; 
            for(int j = i+1; j<n; j++) {
                const auto& p2 = points[j];
                if(p1[0] == p2[0] && p1[1] == p2[1])
                    same_points++;
                else {                    
                    int cur_count = ++count[getSlope(p1, p2)]; 
                    max_points = max(max_points, cur_count);
                } 
            }
            ans = max(ans, same_points+ max_points);
        }
        return ans;
    }
    string getSlope(vector<int> p1, vector<int> p2) {
        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];
        //horizontal line
        if(dy == 0) 
            return to_string(p1[1]) + "_0";
        if(dx == 0)
            return "0_" + to_string(p1[0]);
        int d = gcd(dx, dy);
        return to_string(dy/d) + "_" + to_string(dx/d);
    };
    int gcd( int m, int n) {
        return n==0? m: gcd(n, m%n);
    }
};