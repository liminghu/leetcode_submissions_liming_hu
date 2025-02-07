// https://leetcode.com/problems/check-if-the-rectangle-corner-is-reachable

class Solution {
    vector<int> p; //parent;                   //union-find
    int find(int x) {
        if( x != p[x] )
            p[x] = find( p[x] );
        return p[x];
    }
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        /*
        You are given two positive integers X and Y, and a 2D array circles, where circles[i] = [xi, yi, ri] denotes 
        a circle with center at (xi, yi) and radius ri.
        There is a rectangle in the coordinate plane with its bottom left corner at the origin and top right corner at 
        the coordinate (X, Y). You need to check whether there is a path 
        from the bottom left corner to the top right corner such that the entire path lies inside the rectangle, 
        does not touch or lie inside any circle, 
        and touches the rectangle only at the two corners.
        Return true if such a path exists, and false otherwise.
        */
        
        /*
            3 <= X, Y <= 109
            1 <= circles.length <= 1000
            circles[i].length == 3
            1 <= xi, yi, ri <= 109
        */
        //initialize
        for( int i = 0; i < circles.size(); i++ ) {
            p.push_back(i);
        };

        for( int i = 0; i < circles.size(); i++ ) {
            for( int j = i+1; j < circles.size(); j++ ) {
                long long d =  circles[i][2] + circles[j][2];
                long long dx = circles[i][0] - circles[j][0];
                long long dy = circles[i][1] - circles[j][1];
                if( d * d >= dx * dx + dy * dy ) { //overlap
                    p[find(i)] = find(j); //merge grp i to j
                }
            }
        };

        unordered_map<int, vector<int>> h; // grp id ->(left_x, right_x, lower_y, upper_y);
        for(int i=0; i<p.size(); i++) {
            int j = find(i); //j is the parent of i
            if( h.find(j) == h.end() )
                h[j] = {INT_MAX, INT_MIN, INT_MAX, INT_MIN};
            int left_x  = circles[i][0] - circles[i][2];
            int right_x = circles[i][0] + circles[i][2];
            int lower_y = circles[i][1] - circles[i][2];
            int upper_y = circles[i][1] + circles[i][2];
            h[j] = { min( h[j][0], left_x ), max( h[j][1], right_x ), min( h[j][2], lower_y ), max( h[j][3], upper_y ) };
        }

        for(auto& [k, v]: h) {
            if( v[0] <= 0  && v[1] >= X ) //vertical line is included.
                return false;        
            if( v[2] <= 0  && v[3] >= Y ) //horizontal line is included.
                return false;   
            if( v[0] <= 0  && v[2] <= 0 ) //origin is included.
                return false;
            if( v[1] >= X  && v[3] >= Y ) //top_right is included.
                return false;                                       
        }
        return true;

    }
    
};