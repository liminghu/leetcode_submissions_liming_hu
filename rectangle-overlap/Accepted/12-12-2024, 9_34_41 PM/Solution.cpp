// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //[x1, y1, x2, y2]
         
        int x1 = rec1[0], y1 = rec1[1], x2=rec1[2], y2=rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4=rec2[2], y4=rec2[3];
        //x1 x2    x3 x4 
        return (x1 < x4 && x3 < x2 ) && (y1 < y4 && y3 < y2 );
    }
};