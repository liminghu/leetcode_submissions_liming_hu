// https://leetcode.com/problems/maximum-height-of-a-triangle

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) { //1 <= red, blue <= 100
        int max_height = 100;
        int height = 0;
        int odd = 0;
        int even = 0;
        int min_ball = min(red, blue);
        int max_ball = max(red, blue);
        int minBefore = 0;
        int maxBefore = 0;
        while( maxBefore < max_ball &&   minBefore <= min_ball ) {
            height++;
            if(height % 2 != 0 ) {
                odd += height;
            } else {
                even += height;
            };
            minBefore = min(odd, even);
            maxBefore = max(odd, even);
        }
        
        if(maxBefore == max_ball &&   minBefore == min_ball)
            return height;
        
        return height-1;
        
    }
};