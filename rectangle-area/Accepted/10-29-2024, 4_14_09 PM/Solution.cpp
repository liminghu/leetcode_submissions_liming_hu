// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        int area2 = (bx2-bx1)*(by2-by1);

        //iou
        // x overlap
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int overlapX = right -left;
        //y overlap
        int top = max(ay1, by1);
        int bottom = min(ay2, by2);
        int overlapY = bottom - top;
        int ret = area1+area2;
        if(overlapX >0 && overlapY > 0)
            ret = ret - overlapX * overlapY;
        return ret;
    }
};