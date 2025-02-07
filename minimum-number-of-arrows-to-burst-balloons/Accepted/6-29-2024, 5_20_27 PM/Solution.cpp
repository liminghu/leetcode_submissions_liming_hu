// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as 
a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches 
between xstart and xend. You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon
 with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that
 can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int sz = points.size();
        sort(points.begin(), points.end());
        int ans = 0;
        if(sz <= 1 )
            return sz;

        for(int i=1; i<sz; i++) {
            //xstart_i_1, xend_i_1
                                   //xstart_i, xend_i
            int xstart_i_1 = points[i-1][0], xend_i_1 = points[i-1][1];
            int xstart_i = points[i][0], xend_i = points[i][1];
            if(xend_i_1 < xstart_i)
                ans++;
            else {
            //xstart_i_1,                   xend_i_1
                                   //xstart_i,         xend_i      

            //xstart_i_1,                                       xend_i_1
                                   //xstart_i,         xend_i 
                points[i][1] = min(xend_i, xend_i_1);                                                
            }
        }

        return ans+1;
        
    }
};