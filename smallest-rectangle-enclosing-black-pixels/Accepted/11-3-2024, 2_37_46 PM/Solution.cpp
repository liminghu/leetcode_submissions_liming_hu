// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) { //x: rows   y: columns
        int top = x;
        int bottom = x; 
        int left = y;
        int right = y;
        for(x =0; x<image.size(); x++) {
            for(y =0; y<image[0].size(); y++) {
                if(image[x][y] == '1') {
                    top = min(top, x);
                    bottom = max(bottom, x);
                    left = min(left, y);
                    right = max(right,y);
                }
            }
        }
        return (bottom-top+1)*(right-left+1);
    }
};